#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::warpPerspective(
	cv::InputArray		src,								            // Input image
	cv::0utputArray		dst,								            // Result image 
	cv::InputArray		M,									            // 3-by-3 transform mtx
	cv::Size			dsize,								              // Destination image size
	int					flags = cv::INTER_LINEAR,			        // Interpolation, inverse
	int					borderMode = cv::BORDER_CONSTANT,	    // Extrapolation method
	const cv::Scalar&	borderValue = cv::Scalar()			// For constant borders
);

cv::Mat cv::getPerspectiveTransform(		// Return 3-by-3 matrix
	const cv::Point2f* src,					      // Coordinates of *four* of vertices
	const cv::Point2f* dst,					      // Target coords, three vertices
);
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\Lenna.jpg";
	Mat src = imread(path);
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	
	Point2f srcQuad[] = {
		Point2f(0, 0),				                  // src Top left
		Point2f(src.cols - 1, 0),	              // src Top right
		Point2f(src.cols - 1, src.rows - 1),		// src Bottom left
		Point2f(0, src.rows - 1)
	};

	Point2f dstQuad[] = {
		Point2f(src.cols * 0.05f, src.rows * 0.33f),	  // dst Top left 
		Point2f(src.cols * 0.9f, src.rows * 0.25f),	    // dst Top right
		Point2f(src.cols * 0.8f, src.rows * 0.9f),			// dst Bottom left
		Point2f(src.cols * 0.2f, src.rows * 0.7f),			// dst Bottom left
	};

	//compute affine matrix
	Mat warp_mat = getPerspectiveTransform(srcQuad, dstQuad);
	Mat dst;
	warpPerspective(src, dst, warp_mat, src.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar());

	for (int i = 0; i < 4; i++) 
	{
		cv::circle(dst, dstQuad[i], 5, Scalar(255, 0, 255), -1, 8, 0);
	}

	imshow("Test", dst);
	waitKey();


	return 0;
}
