#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::fastNlMeansDenoising(
	cv::InputArray src,			// Input image
	cv::OutputArray dst,			// Output image
	float h = 3,				// Weight decay parameter
	int templateWindowSize = 7,		// Size of patches used for comparison
	int searchWindowSize = 21		// Maximum patch distance to consider
);

void cv::fastNlMeansDenoisingColored(
	cv::InputArray src,		// Input image
	cv::OutputArray dst,		// Output image
	float h = 3,			// Luminosity weight decay parameter
	float hColor = 3,		// Color weight decay parameter
	int templateWindowSize = 7,	// Size of patches used for comparison
	int searchWindowSize = 21	// Maximum patch distance to consider
);
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\hand2.jpg";
	Mat src = imread(path), dst, src_gray, dst_gray;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	imshow("src_gray", src_gray);

	fastNlMeansDenoising(src_gray, dst_gray);
	imshow("dst_gray", dst_gray);

	fastNlMeansDenoisingColored(src, dst);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}
