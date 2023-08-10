#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::GaussianBlur(
	cv::InputArray		src,					// Input image
	cv::0utputArray 	dst,					// Result image
	cv::Size		ksize,					// Kernel size
	double			sigmaX,					// Gaussian half-width in x-direction
	double 			sigmaY = 0.0,				// Gaussian half-width in y-direction
	int			borderType = cv::BORDER_DEFAULT 	// Border extrapolation to use
);
*/

int main()
{
	float data[9] = {9, 5, 1, 8, 4, 7, 6, 2, 3};
	Mat m0(3, 3, CV_32FC1, data);
	cout << "m0 = \n" <<  m0 << endl;

	Mat m1;
	GaussianBlur(m0, m1, cv::Size(3, 3), 1, 1, BORDER_DEFAULT);
	cout << "m1 = \n" << m1 << endl;

	GaussianBlur(m0, m1, cv::Size(3, 3), 0.5, 0.5, BORDER_DEFAULT);
	cout << "m1 = \n" << m1 << endl;

	GaussianBlur(m0, m1, cv::Size(3, 3), 10, 10, BORDER_DEFAULT);
	cout << "m1 = \n" << m1 << endl;

	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\Lenna.jpg";
	Mat src = imread(path, IMREAD_GRAYSCALE), dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);
	GaussianBlur(src, dst, cv::Size(5, 3), 1, 1, BORDER_DEFAULT);
	imshow("blur1", dst);

	GaussianBlur(src, dst, cv::Size(5, 5), 20, 20, BORDER_DEFAULT);
	imshow("blur2", dst);

	waitKey(0);
	return 0;
}
