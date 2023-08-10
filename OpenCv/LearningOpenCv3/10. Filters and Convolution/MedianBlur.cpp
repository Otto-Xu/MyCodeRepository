#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
	void cv::medianBlur(
		cv::InputArray	src,	// Input image
		cv::OutputArray dst,	// Result image
		cv::Size	ksize	// Kernel size
	);

*/
int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\Lenna.jpg";
	Mat src = imread(path), dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	medianBlur(src, dst, 3);
	imshow("blur1", dst);

	medianBlur(src, dst, 5);
	imshow("blur2", dst);

	waitKey(0);
	return 0;
}
