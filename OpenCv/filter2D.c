#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::filter2D(
	cv::InputArray		src,						// Input image
	cv::0utputArray 	dst,						// Result image
	int			ddepth,						// Output depth(e.g. CV_8U)
	cv::InputArray		kernel,						// Your own kernel
	cv::Pointint		anchor = cv::Point(-1,-1)，			// Location of anchor point
	double 			delta  = 0,					// Offset before assignment
	int			borderType = cv::BORDER_DEFAULT 		// Border extrapolation to use
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
	Laplacian(src, dst, CV_8U, 1, 1, 0, BORDER_DEFAULT);

	Mat element = getStructuringElement(MORPH_RECT, cv::Size(3,3), cv::Point(-1,-1));
	filter2D(dst, dst, CV_8U, element, cv::Point(-1,-1), 0, BORDER_DEFAULT);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}
