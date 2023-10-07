#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
	为了均衡彩色图像，只需均衡亮度通道。
	可以用任何其他彩色图像格式(例如HSV和YCrCb)来分离单个通道中的亮度分量，并对亮度通道进行均衡。
*/

int main()
{
	string path = "C:\\Users\\Administrator\\Desktop\\OpenCv\\Lenna.jpg";
	Mat img = imread(path);
	if (img.empty())
	{
		cout << "read img error" << endl;
		return -1;
	}
	imshow(path, img);

	Mat result;
	Mat ycrcb;

	cvtColor(img, ycrcb, COLOR_BGR2YCrCb);

	vector<Mat> channels;
	split(ycrcb, channels);
	equalizeHist(channels[0], channels[0]);

	merge(channels, ycrcb);

	cvtColor(ycrcb, result, COLOR_YCrCb2BGR);

	imshow("equalized", result);

	waitKey(0);
	return 0;
}
