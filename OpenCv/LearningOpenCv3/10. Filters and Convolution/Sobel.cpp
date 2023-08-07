#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::threshold(
	cv::InputArray		src,			// Input image
	cv::0utputArray		dst,			// Result image
	int			ddepth,			// Pixel depth of output(e.g., CV_8U)
	int			xorder,			// order of corresponding derivative in x
	int			yorder,			// order of corresponding derivative in y
	cv::Size		ksize = 3,		// Kernel size 
	double			scale = 1,		// Scale(applied before assignment)
	double			delta = 0，		// Offset(applied before assignment)
	int			broderType		// Border extrapolation
);

xorder和yorder是求导顺序，其取值范围为0、1和2。0表示在这个方向上不进行求导。
ksize是一个奇数，表示调用的滤波器的宽和高。
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\cat.jpg";
	Mat src = imread(path), dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	Sobel(src, dst, CV_8U, 1, 1, 3, 1, 0, BORDER_DEFAULT);
	imshow("dst1", dst);

	Sobel(src, dst, CV_8U, 1, 0, 3, 1, 0, BORDER_DEFAULT);
	imshow("dst2", dst);

	Sobel(src, dst, CV_8U, 0, 1, 3, 1, 0, BORDER_DEFAULT);
	imshow("dst3", dst);

	Sobel(src, dst, CV_8U, 1, 1, 5, 1, 0, BORDER_DEFAULT);
	imshow("dst4", dst);

	waitKey(0);
	return 0;
}
