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

	//画圆
	circle(src, Point(50, 50), 50, Scalar(255, 0, 0), 2, 4);

	//画椭圆
	ellipse(src, Point(150, 50), Size(100, 50), 70, 0, 360, Scalar(0, 255, 0), 2, 4);

	//画一个填充的简单多边形
	Point p1[4] = { Point(300, 10), Point(350, 20), Point(330, 70), Point(300, 60) };
	fillConvexPoly(src, p1, 4, Scalar(0, 0, 255), 8);

	//画一个填充的任意多边形
	//fillPoly

	//画直线
	line(src, Point(40, 150), Point(140, 200), Scalar(255, 0, 0));

	//画多重折线
	//polyLines

	//画矩形
	rectangle(src, Rect(200, 200, 50, 150), Scalar(0, 255, 0));

	//文字
	putText(src, "Test", Point(300, 200), cv::FONT_HERSHEY_PLAIN, 6, Scalar(0, 0, 255), 2);

	imshow("path", src);

	waitKey(0);
    return 0;
}
