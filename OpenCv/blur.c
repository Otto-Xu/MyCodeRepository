#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::blur(
	cv::InputArray	src,							// Input image
	cv::0utputArray dst,							// Result image
	cv::Size		ksize,							// Kernel size
	cv::Pointint	anchor = cv::Point(-1,-1)，		// Location of anchor point
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

	blur(src, dst, cv::Size(3, 3), cv::Point(-1,-1), BORDER_DEFAULT);
	imshow("blur1", dst);

	blur(src, dst, cv::Size(5, 5), cv::Point(-1, -1), BORDER_DEFAULT);
	imshow("blur2", dst);

	waitKey(0);
	return 0;
}