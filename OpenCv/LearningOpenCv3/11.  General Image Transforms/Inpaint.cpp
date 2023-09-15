#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::inpaint(
	cv::InputArray		src,				// Input image: 8-bit, 1 or 3 channels 
	cv::InputArray		inpaintMask,			// 8-bit, 1 channel. Inpaint nonzeros
	cv::0utputArray		dst,				// Result image
	double			inpaintRadius,			// Range to consider around pixel
	int			flags				// Select NS or TELEA
);
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\LennaBreak.jpg";
	Mat src = imread(path), dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	//转为灰度图
	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	//通过阈值化处理，提取白色污染区域
	Mat imgMask;
	threshold(gray, imgMask, 245, 255, THRESH_BINARY);

	//膨胀
	Mat Kernel = getStructuringElement(MORPH_RECT, Size(3,3));
	dilate(imgMask, imgMask, Kernel);

	//修复白色污染区域
	Mat imgInpaint;
	inpaint(src,imgMask, imgInpaint, 5, INPAINT_NS);

	imshow("inpaint", imgInpaint);

	waitKey(0);
	return 0;
}
