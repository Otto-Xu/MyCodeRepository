#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("C:\\Users\\xuxide\\Desktop\\opencv\\Zebra.jpg");
	imshow("src", src);
	Rect ccomp;
	floodFill(src, Point(100, 100), Scalar(10, 184, 10), &ccomp, Scalar(20, 15, 15), Scalar(20, 15, 15));
	imshow("dst", src);
	waitKey(0);
	return 0;
}
