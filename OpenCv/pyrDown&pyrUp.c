#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::pyrDown(
	cv::InputArray		src,								// Input image 
	cv::0utputArray		dst,								// Result image
	const cv::Size&		dstsize = cv::Size()				// 0utput image size
)

void cv::pyrUp(
	cv::InputArray		src,								// Input image 
	cv::0utputArray		dst,								// Result image
	const cv::Size&		dstsize = cv::Size()				// 0utput image size
)
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

	pyrDown(src, dst, cv::Size());
	imshow("dst1", dst);
	
	pyrUp(src, dst, cv::Size());
	imshow("dst2", dst);

	waitKey(0);
	return 0;
}