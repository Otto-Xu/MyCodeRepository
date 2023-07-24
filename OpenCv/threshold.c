#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
double cv::threshold(
	cv::InputArray		src,				// Input image
	cv::0utputArray		dst,				// Result image
	double			thresh,				// Threshold value
	double			maxValue，			// Max value for upward operations
	int			thresholdType			// Threshold type to use (Example 10-3)
);

阙值类型						操作
cv::THRESH_BINARY				DST = (SRC > thresh) ? MAXVALUE : 0
cv::THRESH_BINARY_INV			DST = (SRC > thresh) ? 0 : MAXVALUE
cv::THRESH_TRUNC				DST = (SRC > thresh) ? THRESH : SRC
cv::THRESH_TOZERO				DST = (SRG > thresh) ? SRC : 0
cv::THRESH_TOZERO_INV			DST = (SRG > thresh) ? 0 : SRC

Ostu算法	对参数thresh传递值cv::THRESH_OTSU
*/


/*
int main()
{
	Mat src, bin, bin_inv, trunc, tozero, tozero_inv;
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\cat.jpg";

	namedWindow("SOURCE", WINDOW_AUTOSIZE);
	namedWindow("BINARY", WINDOW_AUTOSIZE);
	namedWindow("BINARY_INV", WINDOW_AUTOSIZE);
	namedWindow("TRUNC", WINDOW_AUTOSIZE);
	namedWindow("TOZERO", WINDOW_AUTOSIZE);
	namedWindow("TOZERO_INV", WINDOW_AUTOSIZE);

	src = imread(path);
	imshow("SOURCE", src);

	threshold(src, bin, 127, 255, THRESH_BINARY);
	imshow("BINARY", bin);

	threshold(src, bin_inv, 127, 255, THRESH_BINARY_INV);
	imshow("BINARY_INV", bin_inv);

	threshold(src, trunc, 127, 255, THRESH_TRUNC);
	imshow("TRUNC", trunc);

	threshold(src, tozero, 127, 255, THRESH_TOZERO);
	imshow("TOZERO", tozero);

	threshold(src, tozero_inv, 127, 255, THRESH_TOZERO_INV);
	imshow("TOZERO_INV", tozero_inv);

	waitKey(0);
	return 0;
}
*/


void sum_rgb1(const Mat& src, Mat& dst1, Mat& dst2)
{
	//Split image onto the color planes
	vector<Mat> planes;
	split(src, planes);
	Mat b = planes[0], g = planes[1], r = planes[2], s1, s2;

	//先拆出三个通道BGR，取相同权值后相加，为什么需要这样操作呢？得到的却是灰度图，而且和下面直接转灰度图的效果还不一样
	//Add equally weighted rgb values
	addWeighted(r, 1./3., g, 1./3., 0.0, s1);
	addWeighted(s1, 1., b, 1./3., 0.0, s1);
	//Truncate value above 100
	threshold(s1, dst1, 100, 100, THRESH_TRUNC);

	cvtColor(src, s2, COLOR_BGR2GRAY, 0);
	threshold(s2, dst2, 100, 100, THRESH_TRUNC);
}

void sum_rgb2(const Mat& src, Mat& dst)
{
	//Split image onto the color planes
	vector<Mat> planes;
	split(src, planes);
	Mat b = planes[0], g = planes[1], r = planes[2], s1, s2;

	Mat s = Mat::zeros(b.size(), CV_32F);
	accumulate(b, s);
	accumulate(g, s);
	accumulate(r, s);

	threshold(s, s, 100, 100, THRESH_TRUNC);
	s.convertTo(dst, b.type());
}

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\cat.jpg";
	Mat src = imread(path), dst1, dst2;
	if (src.empty()) {
		cout << "can not load" << path << endl;
		return -1;
	}

	//sum_rgb1(src, dst1, dst2);
	sum_rgb2(src, dst1);
	imshow(path, dst1);
	//imshow(path, dst2);

	waitKey(0);
	return 0;
}
