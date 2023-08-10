#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::Scharr(
	cv::InputArray		src,					// Input image
	cv::0utputArray		dst,					// Result image
	int			ddepth,					// Pixel depth of output(e.g., CV_8U)
	int			dx,					// order of corresponding derivative in x
	int			dy,					// order of corresponding derivative in y
	double			scale = 1.0,				// Scale(applied before assignment)
	double			delta = 0.0,				// Offset(applied before assignment)
	int			broderType = BORDER_DEFAULT		// Border extrapolation
);

dx和dy不能同时求导
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\cat.jpg";
	Mat src = imread(path, IMREAD_GRAYSCALE), dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	Sobel(src, dst, CV_8U, 1, 1, 3, 1, 0, BORDER_DEFAULT);
	imshow("SobelDst", dst);

	Mat dst1, dst2, AddDst;

	Scharr(src, dst1, CV_8U, 1, 0);
	imshow("ScharrDstX", dst1);

	Scharr(src, dst2, CV_8U, 0, 1);
	imshow("ScharrDstY", dst2);

	addWeighted(dst1, 0.5, dst2, 0.5, 0, AddDst);
	imshow("AddDst", AddDst);

	waitKey(0);
	return 0;
}
