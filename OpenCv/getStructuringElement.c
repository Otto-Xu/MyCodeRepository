#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::getStructuringElement(
	int				shape,					// Element shape, e.g, cv::MORPH_RECT
	cv::Size			ksize,					// Size of structuring element
	cv::Point			anchor = cv::Point(-1,-1)		// Location of anchor point
);

MORPH_RECT		矩形
MORPH_ELLIPSE	椭圆形
MORPH_CROSS		交叉

有个问题，没法定义这个核里面的元素？
*/

int main()
{
	string path = "C:\\Users\\Administrator\\Desktop\\OpenCv\\Lenna.jpg";
	Mat src = imread(path), src_bin, dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	Mat element = getStructuringElement(MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
	erode(src, dst, element, cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst1", dst);

	erode(src, dst, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst2", dst);

	waitKey(0);
	return 0;
}
