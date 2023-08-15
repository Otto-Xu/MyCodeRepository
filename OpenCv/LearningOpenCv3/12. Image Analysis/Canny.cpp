#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::Canny(
	cv::InputArray   image,                // Input single channel image
	cv::OutputArray  edges,                // Output edge image
	double           threshold1,           // "lower" threshold
	double           threshold2,           // "upper" threshold
	int              apertureSize = 3,     // Sobel aperture
	bool             L2gradient = false    // true=L2-norm (more accurate)
);
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\Lenna.jpg";
	Mat src = imread(path, IMREAD_GRAYSCALE), src_bin, dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	Canny(src, dst, 128, 200);
	imshow("dst1", dst);

	Canny(src, dst, 32, 128);
	imshow("dst2", dst);

	waitKey(0);
	return 0;
}
