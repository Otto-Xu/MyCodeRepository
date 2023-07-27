#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void MatxDemo1() 
{
	//构造函数
	Matx33f m33f_1;
	Matx33f m33f_2(	1, 2, 3, 
			4, 5, 6, 
			7, 8, 9);
	Matx33f m33f_3(m33f_2);

	Matx33f m1 = Matx33f::all(9);	//相同元素的矩阵
	cout << m1 << endl;
	cout << "----------------------" << endl;

	Matx33f m2 = Matx33f::zeros();	//全零矩阵
	cout << m2 << endl;
	cout << "----------------------" << endl;

	Matx33f m3 = Matx33f::ones();	//全一矩阵
	cout << m3 << endl;
	cout << "----------------------" << endl;

	Matx33f m4 = Matx33f::eye();	//单位矩阵
	cout << m4 << endl;
	cout << "----------------------" << endl;
}

void MatxDemo2() 
{
	cv::Matx33f mm(	1, 2, 3, 
			4, 5, 6, 
			7, 8, 9);

	float f = mm(1, 2); //返回第2行第3列数据(注意：从0开始)
	cout << f << endl;
	cout << "----------------------" << endl;

	cv::Matx13f m13 = mm.row(1); //第二行数据赋值给矩阵m13
	cout << m13 << endl;
	cout << "----------------------" << endl;

	cv::Matx31f m31 = mm.col(1); //第二列数据赋值给矩阵m31
	cout << m31 << endl;
	cout << "----------------------" << endl;

	f = m31(0);  //返回矩阵m31第一个数据,一个参数表示是一维矩阵
	cout << f << endl;
	cout << "----------------------" << endl;
}

void MatxDemo3()
{
	cv::Matx33f m(	1, 2, 3,
			4, 5, 6,
			7, 8, 9);

	cv::Matx33f mm = m;  //等于
	cv::Matx33f mmm = m * mm;  //矩阵乘法
	cout << mmm << endl;
	cout << "----------------------" << endl;

	cv::Matx33f m1 = m + mm;  //矩阵加法
	cout << m1 << endl;
	cout << "----------------------" << endl;

	cv::Matx33f m2 = m - mm;  //矩阵减法
	cout << m2 << endl;
	cout << "----------------------" << endl;

	cv::Matx33f m3 = m * 2;  //矩阵乘一个数
	cout << m3 << endl;
	cout << "----------------------" << endl;

	cv::Matx33f m4 = m.t(); //矩阵装置；行列互换
	cout << m4 << endl;
	cout << "----------------------" << endl;

	cv::Matx33f m5 = m.mul(mm);  //对应元素相乘
	cout << m5 << endl;
	cout << "----------------------" << endl;

}

int main()
{
	MatxDemo1();
	cout << "****************************************" << endl;
	MatxDemo2();
	cout << "****************************************" << endl;
	MatxDemo3();

	system("pause");
	return 0;
}
