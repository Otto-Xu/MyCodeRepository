#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void MatAbs_MatAbsDiff()
{
	/*
		作用：计算矩阵的绝对值
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

void MatAdd(Mat m1, Mat m2)
{
	/*
		作用：简单的加法函数

		--dtype
			当两个相加的矩阵数据类型相同时，参数dtype可以默认为-1.
			当两个相加的矩阵数据类型不同时，必须设置输出据很的数据类型
	*/
	Mat m3;
	cv::add(m1, m2, m3);
	cout << m3 << endl;
	cout << "------------------" << endl;

	Mat m4;
	Mat mask(3, 3, CV_8UC1, Scalar(2));
	mask.at<uchar>(0, 1) = 0;
	cv::add(m1, m2, m4, mask, CV_8UC1);
	cout << m4 << endl;
}


void MatAddWeighted(Mat m1, Mat m2)
{
	/*
		作用：权值相加
		两个相加的矩阵数据类型相同，大小相等
	*/
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


void MatBitwise(Mat m1, Mat m2)
{
	/*
		作用：按位与、或、非、异或操作
	*/
	Mat m3;
	cv::bitwise_and(m1, m2, m3);
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

void MatCalcCovarMatrix()
{
	/*
		作用：计算协方差
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
	cout << meanMat1 << endl;
	cout << covMat1 << endl;

	cout << "------------------" << endl;
	Mat_<double> covMat2;
	Mat_<double> meanMat2;
	float data[] = { 1, 4, 7, 3, 6, 9, 2, 5, 8 };
	Mat m1(3, 3, CV_32FC1, data);
	calcCovarMatrix(m1, covMat2, meanMat2, cv::COVAR_ROWS);
	cout << meanMat2 << endl;
	cout << covMat2 << endl;
}


void MatCartToPolar()
{
	/*
		作用1：根据勾股定理求出另一条边的长度和三角形的角度（y/x=tan α）。
		作用2：取梯度幅值和方向。先用sobel求出水平和垂直方向的梯度，再用cartToPolar求出梯度幅值和方向。
		作用3：直角坐标转换极坐标?
	*/
	float data1[] = { 1, 4, 7, 3, 6, 9, 2, 5, 8 };
	float data2[] = { 9, 5, 1, 8, 4, 7, 6, 2, 3 };
	Mat x(3, 3, CV_32FC1, data1);
	Mat y(3, 3, CV_32FC1, data2);

	Mat magnitude, angle;
	cartToPolar(x, y, magnitude, angle);
	cout << magnitude << endl;
	cout << angle << endl;
}

void MatCheckRange(Mat m1)
{
	/*
		作用：检查输入矩阵的每个元素，并确定该元素是否在范围内
	*/
	Point pos(0, 0);
	if (true == checkRange(m1, false, &pos, 0, 10))
	{
		cout << "in range" << endl;
	}
	else
	{
		//抛出异常
	}
}

void MatCompare(Mat m1, Mat m2)
{
	/*
		作用：比较
	*/
	Mat result(3, 3, CV_8UC1);
	compare(m1, m2, result, CMP_EQ);
	cout << result << endl;
}

int main()
{
	char data1[] = { 9, 5, 1, 7, 3, 6, 2, 4, 8 };
	Mat m1(3, 3, CV_8UC1, data1);

	char data2[] = { 7, 4, 1, 8, 5, 2, 9, 6, 3 };
	Mat m2(3, 3, CV_8UC1, data2);

	cout << "----------------MatAbs_MatAbsDiff----------------" << endl;
	MatAbs_MatAbsDiff();

	cout << "----------------MatAdd----------------" << endl;
	MatAdd(m1, m2);

	cout << "----------------MatAddWeighted----------------" << endl;
	MatAddWeighted(m1, m2);

	cout << "----------------MatBitwise----------------" << endl;
	MatBitwise(m1, m2);

	cout << "----------------MatCalcCovarMatrix----------------" << endl;
	MatCalcCovarMatrix();

	cout << "----------------MatCartToPolar----------------" << endl;
	MatCartToPolar();

	cout << "----------------MatCheckRange----------------" << endl;
	MatCheckRange(m1);

	cout << "----------------MatCompare----------------" << endl;
	MatCompare(m1, m2);

	/*
	cout << "----------------MatCompleteSymm------------" << endl;
	MatCompleteSymm(m1, m2);

	cout << "----------------MatConvertScaleAbs------------" << endl;
	MatConvertScaleAbs(m1, m2);

	cout << "----------------MatCountNonZero----------------" << endl;
	MatCountNonZero(m1, m2);

	cout << "----------------MatCvarrToMat----------------" << endl;
	MatCvarrToMat(m1, m2);

	cout << "----------------MatDct----------------" << endl;
	MatDct(m1, m2);

	cout << "----------------MatDft----------------" << endl;
	Matfct(m1, m2);

	cout << "----------------MatCvtColor----------------" << endl;
	MatCvtColor(m1, m2);

	cout << "----------------MatDeterminant----------------" << endl;
	MatDeterminant(m1, m2);

	cout << "----------------MatDivide----------------" << endl;
	MatDivide(m1, m2);
	
	cout << "----------------MatEigen----------------" << endl;
	MatEigen(m1, m2);

	cout << "----------------MatExp----------------" << endl;
	MatExp(m1, m2);

	cout << "----------------MatExtractImageCOI----------------" << endl;
	MatExtractImageCOI(m1, m2);

	cout << "----------------MatFlip----------------" << endl;
	MatFlip(m1, m2);

	cout << "----------------MatGemm----------------" << endl;
	MatGemm(m1, m2);

	cout << "----------------MatGetConvertElem----------------" << endl;
	MatGetConvertElem(m1, m2);

	cout << "----------------MatGetConvertScaleElem----------------" << endl;
	MatGetConvertScaleElem(m1, m2);

	cout << "----------------MatIdct----------------" << endl;
	MatIdct(m1, m2);

	cout << "----------------MatInRange----------------" << endl;
	MatInRange(m1, m2);

	cout << "----------------MatInsertImageCOI----------------" << endl;
	MatInsertImageCOI(m1, m2);

	cout << "----------------MatInvert----------------" << endl;
	MatInvert(m1, m2);

	cout << "----------------MatLog----------------" << endl;
	MatLog(m1, m2);

	cout << "----------------MatLUT----------------" << endl;
	MatLUT(m1, m2);

	cout << "----------------MatMahalanobis----------------" << endl;
	MatMahalanobis(m1, m2);

	cout << "----------------MatMax----------------" << endl;
	MatMax(m1, m2);

	cout << "----------------MatMean----------------" << endl;
	MatMean(m1, m2);

	cout << "----------------MatMeanStdDev----------------" << endl;
	MatMeanStdDev(m1, m2);

	cout << "----------------MatMerge----------------" << endl;
	MatMerge(m1, m2);

	cout << "----------------MatMin----------------" << endl;
	MatMin(m1, m2);

	cout << "----------------MatMinMaxIdx----------------" << endl;
	MatMinMaxIdx(m1, m2);

	cout << "----------------MatMinMaxLoc----------------" << endl;
	MatMinMaxLoc(m1, m2);

	cout << "----------------MatMixChannels----------------" << endl;
	MatMixChannels(m1, m2);

	cout << "----------------MatMulSpectrums----------------" << endl;
	MatMulSpectrums(m1, m2);

	cout << "----------------MatMultiply----------------" << endl;
	MatMultiply(m1, m2);

	cout << "----------------MatMulTransposed----------------" << endl;
	MatMulTransposed(m1, m2);

	cout << "----------------MatNorm----------------" << endl;
	MatNorm(m1, m2);

	cout << "----------------MatNormalize----------------" << endl;
	MatNormalize(m1, m2);

	cout << "----------------MatPerspectiveTransform----------------" << endl;
	MatPerspectiveTransform(m1, m2);

	cout << "----------------MatPhase----------------" << endl;
	MatPhase(m1, m2);
	cout << "----------------MatPolarToCart----------------" << endl;
	MatPolarToCart(m1, m2);
	cout << "----------------MatPow----------------" << endl;
	MatPow(m1, m2);
	cout << "----------------MatRandu----------------" << endl;
	MatRandu(m1, m2);
	cout << "----------------MatRandn----------------" << endl;
	MatRandn(m1, m2);
	cout << "----------------MatRepeat----------------" << endl;
	MatRepeat(m1, m2);
	cout << "----------------MatScaleAdd----------------" << endl;
	MatScaleAdd(m1, m2);
	cout << "----------------MatSetldentity----------------" << endl;
	MatSetldentity(m1, m2);
	cout << "----------------MatSolve----------------" << endl;
	MatSolve(m1, m2);
	cout << "----------------MatSolveCubic----------------" << endl;
	MatSolveCubic(m1, m2);
	cout << "----------------MatSolvePoly----------------" << endl;
	MatSolvePoly(m1, m2);
	cout << "----------------MatSort----------------" << endl;
	MatSort(m1, m2);
	cout << "----------------MatSortIdx----------------" << endl;
	MatSortIdx(m1, m2);
	cout << "----------------MatSplit----------------" << endl;
	MatSplit(m1, m2);
	cout << "----------------MatSqrt----------------" << endl;
	MatSqrt(m1, m2);
	cout << "----------------MatSubtract----------------" << endl;
	MatSubtract(m1, m2);
	cout << "----------------MatSum----------------" << endl;
	MatSum(m1, m2);
	cout << "----------------MatTrace----------------" << endl;
	MatTrace(m1, m2);
	cout << "----------------MatTransform----------------" << endl;
	MatTransform(m1, m2);
	cout << "----------------MatTranspose----------------" << endl;
	MatTranspose(m1, m2);
	*/

	waitKey(0);
	return 0;
}
