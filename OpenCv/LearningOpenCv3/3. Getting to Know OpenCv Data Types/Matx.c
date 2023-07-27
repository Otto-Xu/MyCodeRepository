#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Matx22f m22f;
	m22f = { 1, 2, 3, 4 };
	cout << m22f << endl;
	cout << "----------------------" << endl;

	Matx33f m33f_1(9,8,7,4,5,6,3,2,1);
	cout << m33f_1 << endl;
	cout << "----------------------" << endl;

	Matx23f m23f_1 = cv::Matx23d::all(3);
	cout << m23f_1 << endl;
	cout << "----------------------" << endl;

	Matx33f m33f_2 = cv::Matx33f::eye();
	cout << m33f_2 << endl;
	cout << "----------------------" << endl;

	Matx23f m23f_2 = m23f_1 * m33f_1;
	cout << m23f_2 << endl;
	cout << "----------------------" << endl;

	system("pause");
	return 0;
}
