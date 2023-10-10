#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img(400, 400, CV_8UC3, Scalar(0));
	Point p1(200, 200);
	RotatedRect rr(p1, Size(150, 50), 70);
	
	Point2f p[4];
	rr.points(p);
	for (int i = 0; i < 4; i++) 
	{
		line(img, p[i], p[(i + 1) % 4], Scalar(0, 255, 0), 2);
	}

	Rect brect = rr.boundingRect();
	rectangle(img, brect, Scalar(255, 0, 0), 2);
	circle(img, p1, 1, Scalar(0, 0, 255), 2);

	imshow("img", img);
	waitKey();

	return 0;
}
