#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

//cv::Mat构造函数
void constructors() 
{
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
	Mat m5(cv::Size(4, 4), CV_8UC3, Scalar(1, 5, 9));
	cout << "m5 = \n" << m5 << endl;
	cout << "----------------------" << endl;

	////指定类型的多维数组 
	//一直报错，不懂
	/*
	int size[4] = {1, 2, 3, 4};
	int all = 24;
	float* d1 = new float[all];
	for (int i = 0; i < all; i++) {
		d1[i] = i * 1.0f;
	}
	Mat m6 = Mat(4, size, CV_32S, d1);
	cout << "m6 = \n" << m6 << endl;
	cout << "----------------------" << endl;
	*/

	//复制构造函数
	Mat m7(m5);
	cout << "m7 = \n" << m7 << endl;
	cout << "----------------------" << endl;

	//指定行列的复制构造函数
	Mat m8(m5, cv::Range(0,2), cv::Range(0,3));
	cout << "m8 = \n" << m8 << endl;
	cout << "----------------------" << endl;

	//指定ROI的复制构造函数
	Mat m9(m5, cv::Rect(1, 1, 2, 2));
	cout << "m9 = \n" << m9 << endl;
	cout << "----------------------" << endl;

	//服务于多维数组的复制构造函数
	//不懂怎么用
	//Mat m10(const Mat& mat, const cv::Range* ranges);

	//构造一个如同cv::Vec所指定的数据类型的T,大小为n的一维数组
	cv::Vec<int, 4> vec = {1, 2, 3, 4};
	Mat m11 = Mat(vec, true);
	cout << "m11 = \n" << m11 << endl;
	cout << "----------------------" << endl;

	//构造一个如同cv::Matx所指定的数据类型的T,大小为m * n的二维数组
	cv::Matx<float, 3, 3> m33f = {	1, 2, 3,
					4, 5, 6, 
					7, 8, 9};
	Mat m12(m33f, true);
	cout << "m12 = \n" << m12 << endl;
	cout << "----------------------" << endl;

	//构造一个大小为rows * cols、数据类型为type指定类型的、值全为0的矩阵
	Mat m13 = cv::Mat::zeros(2, 3, CV_8UC1);
	cout << "m13 = \n" << m13 << endl;
	cout << "----------------------" << endl;

	//构造一个大小为rows * cols、数据类型为type指定类型的、值全为1的矩阵
	Mat m14 = cv::Mat::ones(2, 3, CV_8UC3);
	cout << "m14 = \n" << m14 << endl;
	cout << "----------------------" << endl;

	//构造一个大小为rows * cols、数据类型为type指定类型的单位矩阵
	Mat m15 = cv::Mat::eye(3, 3, CV_8UC3);
	cout << "m15 = \n" << m15 << endl;
	cout << "----------------------" << endl;

	/*
		cv::Mat::eye()和cv::Mat::ones()设置多通道时，只有第一通道会被设置为1
	*/
}

void getArrayElement()
{
	Mat m0 = Mat::eye(10, 10, CV_32FC1);
	cout << "Element (3,3) is " << m0.at<float>(3, 3) << endl;

	Mat m1 = Mat::eye(5, 5, CV_32FC2);
	cout << "Element (2,3) is " << m1.at<cv::Vec2f>(2, 3)[0] << ", " << m1.at<cv::Vec2f>(2, 3)[1] << endl;
	cout << "Element (3,3) is " << m1.at<cv::Vec2f>(3, 3)[0] << ", " << m1.at<cv::Vec2f>(3, 3)[1] << endl;

	Mat m2 = Mat(5, 5, CV_8UC3, Scalar(1,5,9));
	cout << "Element (3,3) is " << (int)m2.at<cv::Vec3b>(3, 3)[0] << 
						   ", " << (int)m2.at<cv::Vec3b>(3, 3)[1] << 
						   ", " << (int)m2.at<cv::Vec3b>(3, 3)[2] << endl;

	/*
		ptr返回的是第x行第一个元素的指针
	*/
	cout << *(m1.ptr<cv::Vec2f>(0)) << endl;
	cout << *(m1.ptr<cv::Vec2f>(0) + 1) << endl;
	cout << *(m2.ptr<cv::Vec3b>(0)) << endl;

}

void getBlock() 
{
	/*
		这些都是浅拷贝，通过这些函数对矩阵进行修改时，会修改到原矩阵
	*/
	Mat m(5, 5, CV_8UC3, Scalar(1, 3, 7));
	m.row(2);
	m.col(3);
	m.diag(0);
}

int main()
{
	constructors();
	cout << "//////////////////////////////////////////////////////" << endl;
	getArrayElement();
	cout << "//////////////////////////////////////////////////////" << endl;
	getBlock();
	cout << "//////////////////////////////////////////////////////" << endl;


	waitKey(0);
    return 0;
}
