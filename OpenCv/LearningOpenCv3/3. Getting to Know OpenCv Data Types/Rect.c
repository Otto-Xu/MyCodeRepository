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

	Rect r1(100, 100, 300, 300);
	Rect r2(Point(0, 0), Point(200, 200));
	Rect r3(Point(250, 250), Size(200, 200));

	rectangle(src, r1, Scalar(255, 0, 0));
	rectangle(src, r2, Scalar(0, 255, 0));
	rectangle(src, r3, Scalar(0, 0, 255));

	imshow(path, src);
	waitKey();

	return 0;
}
