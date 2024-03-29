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
### 定义
```
typedef struct CvRect
{
    int x;
    int y;
    int width;
    int height;
#ifdef __cplusplus
    template<typename _Tp>
    operator cv::Rect_<_Tp>() const { return cv::Rect_<_Tp>((_Tp)x, (_Tp)y, (_Tp)width, (_Tp)height); }
#endif
}CvRect;
```
### Rect类基本操作函数
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
### Rect对象的重载操作符
操作|示例
----|----
矩形r1和矩形r2的交集|cv::Rect r3 = r1 & r2; r1 &= r2;
同时包含矩形r1和矩形r2的最小面积矩形|cv::Rect r3 = r1 &#124; r2; r1 &#124;= r2;
平移矩形rx个数量|cv::Rect rx = r + cv::Point(x); r += cv::Point(x);
扩大矩形rs大小|cv::Rect rs = r + cv::Size(s); r += cv::Size(s);
比较矩形r1和矩形r2是否相等|bool eq = (r1 == r2);
比较矩形r1和矩形r2是否不相等|bool ne = (r1 != r2);


----------------------------------------------------------------------------------------------------------------------------------
# RotatedRect类
### 定义
```
class CV_EXPORTS RotatedRect
{
public:
    //构造函数
    RotatedRect();
    RotatedRect(const Point2f& center, const Size2f& size, float angle);
    RotatedRect(const Point2f& point1, const Point2f& point2, const Point2f& point3);

    void points(Point2f pts[]) const;	//返回矩形的4个顶点
    Rect boundingRect() const;			//返回包含旋转矩形的最小矩形
    Rect_<float> boundingRect2f() const;//转换到旧式cvbox2d结构

    Point2f center;	//矩形的质心
    Size2f size;	//矩形的变长
    float angle;	//旋转角度
};
```
cv::RotatedRect()与rr.points(pts[4])、cv::line()结合一起使用画出矩形。
### RotatedRect基本操作函数
操作|示例
----|----
默认构造函数|cv::RotatedRect rr();
复制构造函数|cv::RotatedRect rr2(rr1);
从两个点构造|cv::RotatedRect(p1, p2);
值构造函数|cv::RotatedRect rr(p, sz, theta);
成员访问|rr.center, rr.size, rr.angle
返回四个角的列表|rr.points(pts[4]);
返回包含旋转矩形的最小矩形|rr.boundingRect();


----------------------------------------------------------------------------------------------------------------------------------
# Matx类
### 定义
```
template<typename _Tp, int m, int n> class Matx
{
public:
    enum {
           rows     = m,
           cols     = n,
           channels = rows*cols,
           shortdim = (m < n ? m : n)
         };

    ...
    FUNC();
    ...
}
```
Matx类是固定小型矩阵类。
### Matx基本操作函数
操作|示例
----|----
默认构造函数|cv::Matx33f m33f; cv::Matx43d m43d;
复制构造函数|cv::Matx22d m22d(n22d);
值构造函数|cv::Matx21f m(x0, x1); cv::Matx23d m(x0, x1, x2, x3, x4, x5);
含相同元素的矩阵|m33f = cv::Matx::all(x);
全零矩阵|m23d = cv::Matx23d::zeros();
全一矩阵|m16f = cv::Matx16f::ones();
创建一个单位矩阵|m33f = cv::Matx33f::eye();
创建一个可以容纳另一个矩阵对角线的矩阵|m31f = cv::Mat33f::diag();
创建一个均匀分布的矩阵|m33f = cv::Matx33f::randu(min, max);
创建一个正态分布的矩阵|m33f = cv::Matx33f::nrandn(mean, variance);
成员访问|m(i, j), m(i)
矩阵代数运算|m1 = m0; m0 * m1; m0 + m1; m0 - m1;
单例代数|m * a; a * m; m / a;
比较|m1 == m2; m1 != m2;
点乘|m1.dot(m2);
点乘|m1.ddot(m2);
改变矩阵形状|m91f = m33f.reshape<9,1>();
变换操作符|m44f = (Matx44f) m44d;
提取(i,j)处的2*2子矩阵|m44f.get_minor<2,2>(i,j);
提取第i行|m14f = m44f.row(i);
提取第j列|m41f = m44f.col(j);
提取矩阵对角线|m41f = m44f.diag();
计算转置|n44f = m44f.t();
逆矩阵|n44f = m44f.inv(method);
解线形系统|m31f = m33f.solve(rhs31f, method);<br>m32f = m33f.solve(rhs32f,method);
每个元素的乘法|m1.mul(m2);


----------------------------------------------------------------------------------------------------------------------------------
# Vec类
### 定义
```
template<typename _Tp, int cn> class Vec : public Matx<_Tp, cn, 1>
{
public:
    typedef _Tp value_type;
    enum {
           channels = cn,
#ifdef OPENCV_TRAITS_ENABLE_DEPRECATED
           depth    = Matx<_Tp, cn, 1>::depth,
           type     = CV_MAKETYPE(depth, channels),
#endif
           _dummy_enum_finalizer = 0
         };
    ···
    Func();
    ···
}
```
固定向量类cv::Vec是列为1的cv::Matx<>, 该类拥有相对少的新方法及大量继承自固定矩阵类的方法。
### Vec类基本操作函数
操作|示例
----|----
默认构造函数|Vec2s v2s; Vec6f v6f;
复制构造函数|Vec3f u3f(v3f);
值构造函数|Vec2f v2f(x0, x1); Vec6d v6d(x0, x1, x2, x3, x4, x5);
成员访问|v4f[i];v3w(j);
向量叉乘|v3f.cross(u3f);


----------------------------------------------------------------------------------------------------------------------------------
# Complex类
### 定义
```
template<typename _Tp> class Complex
{
public:

    //! default constructor
    Complex();
    Complex( _Tp _re, _Tp _im = 0 );

    //! conversion to another data type
    template<typename T2> operator Complex<T2>() const;
    //! conjugation
    Complex conj() const;

    _Tp re, im; //< the real and the imaginary parts
};

typedef Complex<float> Complexf;
typedef Complex<double> Complexd;
```
### Complex类基本操作函数
操作|示例
----|----
默认构造函数|cv::Complexf z1; cv::Complexd z2;
复制构造函数|cv::Complexf z2(z1);
值构造函数|cv::Complexd z1(re0); cv::Complexd(re0, im1);
复制构造函数|cv::Complexf u2f(v2f);
成员访问|z1.re; z1.im;
复共轭|z2 = z1.conj();
