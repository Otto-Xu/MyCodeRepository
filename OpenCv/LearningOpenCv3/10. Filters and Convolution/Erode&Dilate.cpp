#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::erode(
	cv::InputArray		src,							// Input image
	cv::0utputArray		dst,							// Result image
	cv::InputArray		element,						// Structuring, a cv::Mat()
	cv::Point		anchor		= cv::Point(-1,-1),			// Location of anchor point
	int			iterations	= 1,					// Number of times to apply
	int			borderType	= cv::BORDER CONSTANT,			// Border extrapolation
	const cv::Scalar&	borderValue 	= cv::morphologyDefaultBorderValue()
);

void cv::dilate(
	cv::InputArray		src,							// Input image
	cv::0utputArray		dst,							// Result image
	cv::InputArray		element,						// Structuring, a cv::Mat()
	cv::Point		anchor		= cv::Point(-1,-1),			// Location of anchor point
	int			iterations	= 1,					// Number of times to apply
	int			borderType	= cv::BORDER CONSTANT,			// Border extrapolation
	const cv::Scalar&	borderValue 	= cv::morphologyDefaultBorderValue()
);
*/

int main()
{
	string path = "C:\\Users\\Administrator\\Desktop\\OpenCv\\ZebraLine.jpg";
	Mat src = imread(path), src_bin, dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}

	//Laplacian(src, src_bin, CV_8U, 3, 1, 0, BORDER_DEFAULT);
	imshow(path, src);

	Mat img;
	erode(src, dst, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("erode", dst);

	dilate(src, dst, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dilate", dst);

	waitKey(0);
	return 0;
}
