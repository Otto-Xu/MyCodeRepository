#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::blur(
	cv::InputArray		src,					// Input image
	cv::0utputArray 	dst,					// Result image
	int			ddepth,					// 0utput depth (e.g.,CV_8U)
	cv::Size		ksize,					// Kernel size
	cv::Pointint		anchor = cv::Point(-1,-1)，		// Location of anchor point
	bool			normalize = true,			// If true, divide by box area 
	int			borderType = cv::BORDER_DEFAULT 	// Border extrapolation to use
);

OpenCV中的函数cv::boxFilter()是一种一般化的形式，而cv::blur()是一种特殊化的形式。
两者之间根本的区别主要是前者可以以非归一化形式调用，并且输出图像深度可以控制 (cv::blur()输出图像的深度与源图像保持一致)。
什么是图像深度？
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

	boxFilter(src, dst, CV_8U, cv::Size(3, 3), cv::Point(-1, -1), true, BORDER_DEFAULT);
	imshow("blur1", dst);

	boxFilter(src, dst, CV_16U, cv::Size(3, 3), cv::Point(-1, -1), true, BORDER_DEFAULT);
	imshow("blur2", dst);

	waitKey(0);
	return 0;
}
