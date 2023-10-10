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
	Point p3[1][5];
	p3[0][0] = Point(100, 350);
	p3[0][1] = Point(200, 300);
	p3[0][2] = Point(300, 350);
	p3[0][3] = Point(150, 400);
	p3[0][4] = Point(70, 380);
	const Point* ppts[] = { p3[0] };
	int npt[] = { 5 };
	fillPoly(src, ppts, npt, 1, Scalar(255, 0, 255), 8, 0);

	//画直线
	line(src, Point(40, 150), Point(140, 200), Scalar(255, 0, 0));

	//画多重折线
	Point p4[1][5];
	p4[0][0] = Point(300, 350);
	p4[0][1] = Point(300, 320);
	p4[0][2] = Point(300, 150);
	p4[0][3] = Point(350, 200);
	p4[0][4] = Point(370, 380);
	const Point* pppts[] = { p4[0] };
	polylines(src, pppts, npt, 1, true, Scalar(0, 200, 200), 2);

	//画矩形
	rectangle(src, Rect(200, 200, 50, 150), Scalar(0, 255, 0));

	//文字
	putText(src, "Test", Point(300, 200), cv::FONT_HERSHEY_PLAIN, 6, Scalar(0, 0, 255), 2);

	imshow("path", src);

	waitKey(0);
    return 0;
}
