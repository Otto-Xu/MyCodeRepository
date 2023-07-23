#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;


/*
void cv::adaptiveThreshold(
	cv::InputArray	src,					// Input image
	cv::0utputArray	dst,					// Result image
	double			maxValue，				// Max value for upward operations
	int				adaptiveMethod.			// mean or Gaussian
	int				thresholdType，,		// Threshold type to use (Example 10-3)
	int				blockSize,				// Block size
	double			C						// Constant
)

	cv::adaptiveThreshold()根据adaptiveMethod的设置，允许两种不同的自适应阙值方法。
	两种方法都是逐个像素地计算自适应阙值T(x,y)，方法是通过计算每个像素位置周围的b x b区域的加权平均值然后减去常数C，其中b由blocksize给定。
	相对于一般的阈值化操作，当图像中出现较大的明暗差异时，自适应阈值时非常有效。
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\cat.jpg";
	Mat Igray = imread(path, IMREAD_GRAYSCALE);
	if (Igray.empty()) 
	{
		cout << "can not load " << path << endl;
		return -1;
	}

	double fixed_thrshold = 127;
	int threshold_type = THRESH_BINARY;
	int adaptive_method = ADAPTIVE_THRESH_GAUSSIAN_C;
	int block_size = 5;
	double offset = 0;

	Mat It, Iat;
	threshold(Igray, It, fixed_thrshold, 255, threshold_type);
	adaptiveThreshold(Igray, Iat, 255, adaptive_method, threshold_type, block_size, offset);

	imshow("Raw", Igray);
	imshow("Threshold", It);
	imshow("Adaptive Threshold", Iat);

	waitKey(0);
	return 0;
}
