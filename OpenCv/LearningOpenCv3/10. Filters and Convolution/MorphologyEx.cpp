#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::morphologyEx(
	cv::InputArray		src,							// Input image
	cv::0utputArray		dst,							// Result image
	int			op,							// Operator(e.g. MORPH_OPEN)
	cv::InputArray		element,						// Structuring, a cv::Mat()
	cv::Point		anchor		= cv::Point(-1,-1),			// Location of anchor point
	int			iterations	= 1，					// Number of times to apply
	int			borderType	= cv::BORDER_CONSTANT			// Border extrapolation
	const cv::Scalar&	borderValue     = cv::morphologyDefaultBorderValue() 
);

MORPH_OPEN		开操作，先腐蚀再膨胀（两次开操作，操作顺序是腐蚀腐蚀膨胀膨胀）
MORPH_CLOSE		闭操作，先膨胀再腐蚀
MORPH_TOPHAT		顶帽操作，TopHat(src) = src - open(src)		//Isolate brighter，得到了比源图像更亮的环绕部分
MORPH_BLACKHAT		底帽操作，BlackHat(src) = close(src) - src	//Isolate dimmer ， 得到了比源图像更暗的环绕部分
MORPH_GRADIENT		形态学梯度，gradient(src) = dilate(src) - erode(src)
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\hand1.jpg";
	Mat src = imread(path), src_bin, dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}

	//Laplacian(src, src_bin, CV_8U, 3, 1, 0, BORDER_DEFAULT);
	imshow(path, src);

	morphologyEx(src, dst, MORPH_OPEN, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst1", dst);

	morphologyEx(src, dst, MORPH_CLOSE, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst2", dst);

	morphologyEx(src, dst, MORPH_TOPHAT, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst3", dst);

	morphologyEx(src, dst, MORPH_BLACKHAT, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst4", dst);

	morphologyEx(src, dst, MORPH_GRADIENT, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst5", dst);

	waitKey(0);
	return 0;
}
