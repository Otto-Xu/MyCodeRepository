#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::warpAffine(
	cv::InputArray		src,								        // Input image
	cv::0utputArray		dst,								        // Result image 
	cv::InputArray		M,									        // 2-by-3 transform mtx
	cv::Size			dsize,								          // Destination image size
	int					flags = cv::INTER_LINEAR,			    // Interpolation, inverse
	int					borderMode = cv::BORDER_CONSTANT,	// Pixel extrapolation
	const cv::Scalar&	borderValue = cv::Scalar()	// For constant borders
);

cv::Mat cv::getAffineTransform(		// Return 2-by-3 matrix
	const cv::Point2f* src,			    // Coordinates *three* of vertices
	const cv::Point2f* dst,			    // Target coords, three vertices
);

cv::Mat cv::getRotationMatrix2D(	// Return 2-by-3 matrix
	cv::Point2f			center,		      // Center of rotation
	const cv::Point2f*	src,		    // Angle of rotation
	const cv::Point2f*	dst,		    // Rescale after rotation
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
	
	Point2f srcTri[] = {
		Point2f(0, 0),				// src Top left
		Point2f(src.cols - 1, 0),	// src Top right
		Point2f(0,src.rows - 1)		// src Bottom left
	};

	/*
	Point2f dstTri[] = {
		Point2f(src.cols * 0.f, src.rows * 0.33f),	  // dst Top left 
		Point2f(src.cols * 0.85f, src.rows * 0.25f),  // dst Top right
		Point2f(src.cols * 0.15f, src.rows * 0.7f),	  // dst Bottom left
	};
	*/

	Point2f dstTri[] = {
	Point2f(src.cols * 0.f, src.rows * 0.5f),	  // dst Top left 
	Point2f(src.cols * 0.5f, src.rows * 0.f),	  // dst Top right
	Point2f(src.cols * 0.5f, src.rows),			    // dst Bottom left
	};

	//compute affine matrix
	Mat warp_mat = getAffineTransform(srcTri, dstTri);
	Mat dst, dst2;
	warpAffine(src, dst, warp_mat, src.size(), INTER_LINEAR, BORDER_CONSTANT, cv::Scalar());
	for (int i = 0; i < 3; ++i) {
		circle(dst, dstTri[i], 5, cv::Scalar(255,0,255), -1, 8, 0);
	}

	cv::imshow("Affine Transform", dst);
	cv::waitKey();

	for (int frame = 0;; ++frame) {
		//compute rotation matrix
		Point2f center(src.cols * 0.5f, src.rows * 0.5f);
		double angle = frame * 3 % 360, scale = (cos((angle - 60) * 3.14 / 180) + 1.05) * 0.8;
		Mat rot_mat = getRotationMatrix2D(center, angle, scale);
		warpAffine(src, dst, rot_mat, src.size(), INTER_LINEAR, BORDER_CONSTANT, cv::Scalar());
		cv::imshow("Rotated Image", dst);
		if (cv::waitKey(30) >= 0) {
			break;
		}
	}

	return 0;
}
