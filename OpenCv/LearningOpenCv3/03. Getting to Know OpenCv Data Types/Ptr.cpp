#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    cv::Ptr<cv::Matx33f> pp = new(cv::Matx33f);  //创建一个智能指针p，空构造
    cv::Ptr<cv::Matx33f> p =makePtr<cv::Matx33f>();

    bool b = p.empty();  //是否为空
    p[0] = { 10,20,30,40,50,60,70,80,90 };

    cout << "--------------------" << endl;
    cout << p[0] << endl;
    cout << "--------------------" << endl;

    p.release();  //释放空间
    b = p.empty();//释放之后为空


    system("pause");
    return 0;
}
