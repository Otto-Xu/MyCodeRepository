#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::Laplacian(
	cv::InputArray		src,			// Input image
	cv::0utputArray		dst,			// Result image
	int					ddepth,			// Depth of output image (e.g., CV_8U)
	cv::Size			ksize = 3,		// Kernel size
	double				scale = 1,		// Scale(applied before assignment to dst)
	double				delta = 0£¬		// Offset(applied before assignment to dst)
	int					broderType		// Border extrapolation
);
*/

int main()
{
	string path = "C:\\Users\\Administrator\\Desktop\\OpenCv\\Lenna.jpg";
	Mat src = imread(path), dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	Laplacian(src, dst, CV_8U, 3, 1, 0, BORDER_DEFAULT);
	imshow("dst1", dst);

	Laplacian(src, dst, CV_8U, 3, 2, 0, BORDER_DEFAULT);
	imshow("dst2", dst);

	Laplacian(src, dst, CV_8U, 3, 1, 1, BORDER_DEFAULT);
	imshow("dst3", dst);

	Laplacian(src, dst, CV_8U, 5, 1, 0, BORDER_DEFAULT);
	imshow("dst4", dst);

	Mat add_img;
	add(src, dst, add_img, noArray(), -1);
	imshow("add", add_img);

	waitKey(0);
	return 0;
}