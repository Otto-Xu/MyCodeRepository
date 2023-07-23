#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::GaussianBlur(
	cv::InputArray	src,							// Input image
	cv::0utputArray dst,							// Result image
	cv::Size		ksize,							// Kernel size
	double			sigmaX,							// Gaussian half-width in x-direction
	double 			sigmaY = 0.0,					// Gaussian half-width in y-direction
	int				borderType = cv::BORDER_DEFAULT // Border extrapolation to use
);
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\hand1.jpg";
	Mat src = imread(path), dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	GaussianBlur(src, dst, cv::Size(5, 3), 1, 0.5, BORDER_DEFAULT);
	imshow("blur1", dst);

	GaussianBlur(src, dst, cv::Size(5, 5), 0.0, 0.0, BORDER_DEFAULT);
	imshow("blur2", dst);

	waitKey(0);
	return 0;
}