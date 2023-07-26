# Point类
### 定义
```
typedef struct CvPoint
{
    int x;
    int y;
#ifdef __cplusplus
    template<typename _Tp>
    operator cv::Point_<_Tp>() const { return cv::Point_<_Tp>(cv::saturate_cast<_Tp>(x), cv::saturate_cast<_Tp>(y)); }
#endif
}CvPoint;
```
Point类主要有两种模板，一种是二维的点Point2x，一种是三维的点Point3x，x可选如下：
选项|含义
----|----
b|unsigned char
s|short int
i|32-bit int
f|32-bit float
d|64-bit float
### Point类基本操作函数
操作|示例
--------|-----------
默认构造函数|cv::Point2i p;<br>cv::Point3i p;
复制构造函数|cv::Point2f p2(p1);
值构造函数|cv::Point2i(x0, x1);<br>cv::Point3d p(x0, x1, x2);
构造成固定向量类|(cv::Vec3f) p;
成员访问|p.x, p.y, p.z
点乘|float x = p1.dot(p2);
双精度点乘|double x = p1.dot(p2);
叉乘|p1.cross(p2);
判断点p是否在矩形r内|p.inside(r);

----------------------------------------------------------------------------------------------------------------------------------
# Scalar类
### 定义
```
typedef struct CvScalar
{
    double val[4];
#ifdef __cplusplus
    template<typename _Tp>
    operator cv::Scalar_<_Tp>() const { return cv::Scalar_<_Tp>(cv::saturate_cast<_Tp>(val[0]), cv::saturate_cast<_Tp>(val[1]), cv::saturate_cast<_Tp>(val[2]), cv::saturate_cast<_Tp>(val[3])); }
#endif
}CvScalar;
```
Scalar是一个由长度为4的数组作为元素构成的结构体，Scalar最多可以存储四个值，没有提供的值默认为0。  
Scalar通常用于对图像通道数进行处理。
### Scalar类基本操作函数
操作|示例
-----|------
默认构造函数|cv::Scalar s;
复制构造函数|cv::Scalar s2(s1);
值构造函数|cv::Scalar s(x0);<br>cv::Scalar s(x0, x1, x2, x3);
元素相乘|s1.mul(s2);
(四元数)共轭|s.conj(); //(return cv::Scalar(s0, -s1, -s2, -s3))
(四元数)真值测试|s.isReal(); //(return true if s1==s2==s3==0)


----------------------------------------------------------------------------------------------------------------------------------
# Size类
### 定义
```
typedef struct CvSize
{
    int width;
    int height;
#ifdef __cplusplus
    template<typename _Tp>
    operator cv::Size_<_Tp>() const { return cv::Size_<_Tp>(cv::saturate_cast<_Tp>(width), cv::saturate_cast<_Tp>(height)); }
#endif
}CvSize;
```
Size类在实际操作时与Point类相似，而且可以与Point类互相转换。
### Size类基本操作函数
操作|示例
----|----
默认构造函数|cv::Size sz;<br>cv::Size2i sz;<br>cv::Size2f sz;
复制构造函数|cv::Size sz2(sz1);
值构造函数|cv::Size2f sz(w, h);
成员访问|sz.width; sz.height;
计算面积|sz.area();


----------------------------------------------------------------------------------------------------------------------------------
# Rect类
操作|示例
----|----
默认构造函数|cv::Rect r;
复制构造函数|cv::Rect r2(r1);
值构造函数|cv::Rect(x, y, w, h);
由起始点和大小构造|cv::Rect(p, sz);
由两个对角构造|cv::Rect(p1, p2);
成员访问|r.x; r.y; r.width; r.height; 
计算面积|r.area();
提取左上角|r.tl();
提取右下角|r.br();
判断点p是否在矩形r内|r.contaions(p);
