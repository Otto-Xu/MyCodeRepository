#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\Lenna.jpg";
	Mat src = imread(path);
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}

	//值构造函数
	Rect r1(100, 100, 300, 300);
	rectangle(src, r1, Scalar(255, 0, 0));

	//由两个对角构造
	Rect r2(Point(0, 0), Point(200, 200));
	rectangle(src, r2, Scalar(0, 255, 0));

	//由起始点和大小构造
	Rect r3(Point(250, 250), Size(200, 200));
	rectangle(src, r3, Scalar(0, 0, 255));

	//平移矩形r1
	Point p1(50, 50);
	Rect r4 = r1 + p1;
	rectangle(src, r4, Scalar(255, 0, 255));
	imshow(path, src);

	//扩大矩形r1
	Size s1(50, 50);
	Rect r5 = r1 + s1;
	rectangle(src, r5, Scalar(0, 255, 255));

	imshow(path, src);
	waitKey();

	return 0;
}
