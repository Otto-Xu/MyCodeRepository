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

	bilateralFilter(src, dst, -1, 1, 10, BORDER_DEFAULT);
	imshow("blur1", dst);

	bilateralFilter(src, dst, 9, 0.0, 150, BORDER_DEFAULT);
	imshow("blur2", dst);

	waitKey(0);
	return 0;
}
