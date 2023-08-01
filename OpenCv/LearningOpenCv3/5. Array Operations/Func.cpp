#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void MatAbs_MatAbsDiff()
{
	/*
		实际上，对cv::abs()的调用会转换为对cv::absdiff()或其他函数的调用。
		m2 = cv::abs(m0 - m1) 转换为 cv::absdiff(m0, m1, m2)
		m2 = cv::abs(m0) 转换为 cv::absdiff(m0, cv::Scalar::all(0), m2)
		m2 = cv::Mat_<Vec<uchar>, n>>(cv::abs(alpha*m0 + beta)) 转换为 cv::convertScaleAbs(m0, m2, alpha, beta)
	*/

	float data[] = { -1, -2, -3, 4, 5, 6, 7, 8, 9 };
	Mat m1(cv::Size(3, 3), CV_32FC1, data);
	cout << m1 << endl;
	cout << "------------------" << endl;

	Mat m2 = cv::abs(m1);
	cout << m2 << endl;
	cout << "------------------" << endl;
	
	Mat m3;
	cv::absdiff(m1, m2, m3);
	cout << m3 << endl;
}

void MatAdd()
{
	/*
	--mask
		什么东西啊？类似ROI？
	--dtype
		当两个相加的矩阵数据类型相同时，参数dtype可以默认为-1.
		当两个相加的矩阵数据类型不同时，必须设置输出据很的数据类型
	*/
	Mat m1(4, 4, CV_8UC1, Scalar(8));
	Mat m2(4, 4, CV_8UC1, Scalar(4));
	Mat m3;
	cv::add(m1, m2, m3);
	cout << m3 << endl;
	cout << "------------------" << endl;
	
	Mat m4;
	Mat mask(4, 4, CV_8UC1, Scalar(2));
	mask.at<uchar>(0, 1) = 0;
	cv::add(m1, m2, m4, mask);
	cout << m4 << endl;
}


void MatAddWeighted()
{
	/*
		两个相加的矩阵数据类型相同，大小相等
	*/
	Mat m1(3, 3, CV_8UC1, Scalar(5));
	Mat m2(3, 3, CV_8UC1, Scalar(10));
	Mat m3;
	cv::addWeighted(m1, 0.2, m2, 0.8, 0, m3, -1);
	cout << m3 << endl;

	string path1 = "C:\\Users\\xuxide\\Desktop\\opencv\\Lenna.jpg";
	Mat src1 = imread(path1, WINDOW_AUTOSIZE);

	string path2 = "C:\\Users\\xuxide\\Desktop\\opencv\\cat.jpg";
	Mat src2 = imread(path2, WINDOW_AUTOSIZE);

	//浅拷贝，修改roi2的同时会对src2进行修改
	Mat roi1(src1, cv::Rect(250, 250, 40, 30));
	Mat roi2(src2, cv::Rect(240, 170, 40, 30));

	cv::addWeighted(roi1, 1, roi2, 0, 0, roi2, -1);
	imshow("dst", src2);
}

void MatBitwise()
{
	float data1[] = { 9, 5, 1, 7, 3, 6, 2, 4, 8 };
	Mat m1(3, 3, CV_32FC1, data1);

	float data2[] = { 7, 4, 1, 8, 5, 2, 9, 6, 3 };
	Mat m2(3, 3, CV_32FC1, data2);

	Mat m3;
	cv::bitwise_and(m1 ,m2 ,m3);
	cout << m3 << endl;
	cout << "------------------" << endl;

	Mat m4;
	cv::bitwise_not(m1, m4);
	cout << m4 << endl;
	cout << "------------------" << endl;

	Mat m5;
	cv::bitwise_or(m1, m2, m5);
	cout << m5 << endl;
	cout << "------------------" << endl;

	Mat m6;
	cv::bitwise_xor(m1, m2, m6);
	cout << m6 << endl;
	cout << "------------------" << endl;
}

void MatcalcCovarMatrix()
{
	/*
		calcCovarMatrix的两种重载方法
		第一种方法的参数1不能是单独一个n*m的矩阵，必须是有n个1*m(或是m个n*1)的矩阵组成
		第二种方法的参数1可以是单独一个矩阵，但是flag指定cv::COVAR_ROWS或cv::COVAR_COLS
		奇奇怪怪的
	*/
	Mat_<float> samples[3];
	for (int i = 0; i < 3; i++)
	{
		samples[i].create(1, 3);
		samples[i](0, 0) = i * 3 + 1;
		samples[i](0, 1) = i * 3 + 2;
		samples[i](0, 2) = i * 3 + 3;
	}
	Mat_<double> covMat1;
	Mat_<double> meanMat1;
	calcCovarMatrix(samples, 3, covMat1, meanMat1, cv::COVAR_NORMAL);
	cout << "meanMat1" << meanMat1 << endl;
	cout << "covMat1" << covMat1 << endl;

	cout << "------------------" << endl;
	Mat_<double> covMat2;
	Mat_<double> meanMat2;
	float data[] = { 1, 4, 7, 3, 6, 9, 2, 5, 8 };
	Mat m1(3, 3, CV_32FC1, data);
	calcCovarMatrix(m1, covMat2, meanMat2, cv::COVAR_ROWS);
	cout << "meanMat2" << meanMat2 << endl;
	cout << "covMat2" << covMat2 << endl;
}

int main()
{
	cout << "----------------MatAbs_MatAbsDiff----------------" << endl;
	MatAbs_MatAbsDiff();

	cout << "----------------MatAdd----------------" << endl;
	MatAdd();

	cout << "----------------MatAddWeighted----------------" << endl;
	MatAddWeighted();

	cout << "----------------MatBitwise----------------" << endl;
	MatBitwise();

	cout << "----------------MatcalcCovarMatrix----------------" << endl;
	MatcalcCovarMatrix();

	waitKey(0);
  return 0;
}
