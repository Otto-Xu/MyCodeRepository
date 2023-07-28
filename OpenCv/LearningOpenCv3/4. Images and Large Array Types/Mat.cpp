#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	//cv::Mat构造函数
	//空构造
	Mat m1;
	cout << "m1 = \n" << m1 << endl;
	cout << "----------------------" << endl;

	//指定类型的二维数组，默认初始值205
	Mat m2(3, 3, CV_8UC1);
	cout << "m2 = \n" << m2 << endl;
	cout << "----------------------" << endl;

	//指定类型的二维数组，并指定初始化值
	Mat m3(3, 3, CV_8UC3, Scalar(3, 4, 5));
	cout << "m3 = \n" << m3 << endl;
	cout << "----------------------" << endl;

	//指定类型的二维数组，并指定预先存储的数据
	//这里好像有坑
	Mat m4(3, 3, CV_8UC1, m3.data);
	cout << "m4 = \n" << m4 << endl;
	cout << "----------------------" << endl;

	//指定类型的二维数组(大小由size指定)
	Mat m5(cv::Size(3, 3), CV_8UC1);
	cout << "m5 = \n" << m5 << endl;
	cout << "----------------------" << endl;

	////指定类型的多维数组
	int array[2][2][2] = {3, 2, 1};
	int* size = array;
	Mat m6(3, size, CV_8UC1);
	cout << "m6 = \n" << m6 << endl;
	cout << "----------------------" << endl;

	waitKey(0);
    return 0;
}
