#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::resize(
	cv::InputArray		src,						// Input image 
	cv::0utputArray		dst,						// Result image
	cv::Size		dsize,						// New size
	double			fx = 0,						// x-rescale
	double			fy = 0,						// y-rescale
	int			interpolation = CV::INTER_LINEAR		// interpolation method
)
cv::INTER_NEAREST	最近邻插值
cv::INTER_LINEAR	双线性插值
cv::INTER_AREA		像素区域重采样
cv::INTER_CUBIC		双三次插值
cv::INTER_LANCZOS4	插值(超过8x8个邻域)
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

	resize(src, dst, cv::Size(0,0), 2, 0.2, INTER_LINEAR);
	imshow("dst1", dst);

	resize(src, dst, cv::Size(200, 200), 0, 0, INTER_LINEAR);
	imshow("dst2", dst);

	resize(src, dst, cv::Size(0, 0), 1.5, 0.5, INTER_NEAREST);
	imshow("dst3", dst);

	resize(src, dst, cv::Size(200, 200), 0, 0, INTER_NEAREST);
	imshow("dst4", dst);

	waitKey(0);
	return 0;
}
