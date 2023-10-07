#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
	感觉有得研究，不懂的地方有点多
*/

int main()
{
	string path = "C:\\Users\\Administrator\\Desktop\\OpenCv\\Lenna.jpg";
	Mat img = imread(path);
	if (img.empty())
	{
		cout << "read img error" << endl;
		return -1;
	}
	imshow(path, img);

	Mat result;
	const double exponential_e = std::exp(1.0);

	Mat lut(1, 256, CV_8UC1);
	for (int i = 0; i < 256; i++)
	{
		float x = (float)i / 256.0;
		lut.at<uchar>(i) = cvRound(256 * (1 / (1 + pow(exponential_e, -((x - 0.5) / 0.1)))));
	}

	vector<Mat> bgr;
	split(img, bgr);
	LUT(bgr[2], lut, bgr[2]);
	merge(bgr, result);

	Mat halo(img.rows, img.cols, CV_32FC3, Scalar(0.3, 0.3, 0.3));
	circle(halo, Point(img.cols / 2, img.rows / 2), img.cols / 3, Scalar(1, 1, 1), -1);

	blur(halo, halo, Size(img.cols / 3, img.cols / 3));
	Mat resultf;
	result.convertTo(resultf, CV_32FC3);

	multiply(resultf, halo, resultf);
	resultf.convertTo(result, CV_8UC3);

	imshow("Lomography", result);

	waitKey(0);
	return 0;
}
