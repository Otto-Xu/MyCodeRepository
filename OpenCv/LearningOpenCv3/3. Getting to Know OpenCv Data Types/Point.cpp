#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	vector<Point2f> vp2f;
	vp2f.push_back(Point2f(2, 3));
	vp2f.push_back(Point2f(4, 5));
	vp2f.push_back(Point2f(6, 7));
	cout << "二维点向量" << endl << vp2f << endl;

	vector<Point3f> vp3f(3);
	Point3f p1;
	p1.x = 1;
	p1.y = 2;
	p1.z = 3;
	vp3f[0] = p1;

	Point3f p2(p1);
	vp3f[1] = p2;

	vp3f[2] = Point3f(4, 5, 6);
	cout << "三维点向量" << endl << vp3f << endl;

	system("pause");
	return 0;
}
