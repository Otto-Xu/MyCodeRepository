#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void scalar_demo1()
{
	Mat M(4, 4, CV_32FC2, Scalar(1, 3));
	cout << M << endl;
}

void scalar_demo2()
{
	Mat M(4, 4, CV_32FC3, Scalar(1, 3, 5));
	cout << M << endl;
}


void scalar_demo3()
{
	Mat M(4, 4, CV_32FC4, Scalar(1, 3, 5));
	cout << M << endl;
}

void scalar_demo4() 
{
	Mat blue_m(	256, 256, CV_8UC3, Scalar(255, 0, 0));
	Mat green_m(256, 256, CV_8UC3, Scalar(0, 255, 0));
	Mat red_m(	256, 256, CV_8UC3, Scalar(0, 0, 255));

	imshow("blue",	blue_m);
	imshow("green",	green_m);
	imshow("red",	red_m);
	waitKey(0);
}

int main()
{
	scalar_demo1();
	cout << "------------------------" << endl;
	scalar_demo2();
	cout << "------------------------" << endl;
	scalar_demo3();
	cout << "------------------------" << endl;

	scalar_demo4();

	system("pause");
	return 0;
}
