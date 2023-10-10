#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void SmPtr() 
{
	/*
		uchar* ptr(int i0, bool createMissing, size_t * hashval = 0)
		bool createMissing		//是否为元素申请内存，1：申请内存，0：不申请内存
		size_t * hashval = 0	//默认为0，计算hash key，再查找hash表。可以提前计算hash值，提高算法效率
		返回一个指向无符号字符型的指针(uchar*)，需要强转为正确的类型
	*/

	int size[2] = { 4, 4 };
	SparseMat sm(2, size, CV_8UC1);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			*sm.ptr(i, j, 1) = i * j;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			/*
				因为SpareseMat矩阵中存储的是一张hash表，不是连续的，
				所以不可以通过指针偏移的方式访问到下一个元素
			*/
			cout << (int)*sm.ptr(i, j, 1) << endl;
		}
	}
}

void SmRef()
{
	/*
		ref相当于*(_Tp*)ptr(i0, ..., true, hashval)，返回一个元素的引用
		ref模板能够适应各种数据类型，而ptr中需要根据相应的数据类型进行强转
	*/
	int size[2] = { 4, 4 };
	SparseMat sm(2, size, CV_8UC1);
	size_t* hashval = NULL;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sm.ref<int>(i, j, hashval) = i * j;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			cout << sm.ref<int>(i, j, hashval) << endl;
		}
	}
}

void SmFind()
{
	/*
		find只读不写，返回为一个指针
	*/

	int size[2] = { 4, 4 };
	SparseMat sm(2, size, CV_8UC1);
	size_t* hashval = NULL;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sm.ref<int>(i, j, hashval) = i * j;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << *sm.find<int>(i, j, hashval) << endl;
		}
	}
}

void SmValue()
{
	/*
		value只读不写，返回为一个元素
	*/
	int size[2] = { 4, 4 };
	SparseMat sm(2, size, CV_8UC1);
	size_t* hashval = NULL;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sm.ref<int>(i, j, hashval) = i * j;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << sm.value<int>(i, j, hashval) << endl;
		}
	}
}

int main()
{
	SmPtr();
	cout << "-----------------" << endl;
	SmRef();
	cout << "-----------------" << endl;
	SmFind();
	cout << "-----------------" << endl;
	SmValue();
	cout << "-----------------" << endl;

	waitKey(0);
    return 0;
}
