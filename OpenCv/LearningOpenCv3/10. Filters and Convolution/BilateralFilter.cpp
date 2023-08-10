#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::bilateralFilter(
	cv::InputArray		src,					// Input image
	cv::0utputArray 	dst,					// Result image
	int 			d,					// Pixel neighborhood size(max distance)
	double			sigmaColor,				// Width param for color.weight function
	double 			sigmaSpace,				// Width param for spatial.weight function
	int			borderType = cv::BORDER_DEFAULT 	// Border extrapolation to use
);

sigmaColor值越大，平滑时所包括的强度(色彩)越大，因此图像的不连续性将会更显著。
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\Lenna.jpg";
	Mat src = imread(path), dst1, dst2;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	GaussianBlur(src, dst1, cv::Size(3,3), 0, 0);
	imshow("dst1", dst1);

	bilateralFilter(src, dst2, 5, 1, 10, BORDER_DEFAULT);
	imshow("blur1", dst2);

	bilateralFilter(src, dst2, 9, 200, 10, BORDER_DEFAULT);
	imshow("blur2", dst2);

	waitKey(0);
	return 0;
}
