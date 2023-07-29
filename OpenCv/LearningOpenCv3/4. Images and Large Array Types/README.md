# cv::Mat类
### 概述
|组成|描述|
|---|---|
|矩阵头|表示它所包含数组类型的元素`flag`<br>表示其维度的元素`dims`<br>表示行和列的数目的元素`rows`和`cols`(dims大于2时无效)
|指针|一个指向数据真正存储位置的`data`指针<br>一个引用计数器`refcount`
|补充|`flag`是int类型，共占32位。<br>0-2位代表depth，3-11代表通道数channels，0-11位共同代表type(如CV_8UC3)。<br>14位代表Mat的内存是否连续。<br>15位代表该Mat是否为某一个Mat的submatrix。<br>16-31位代表magic signature，区分Mat的类型，如Mat和SparseMat。
  
Mat类的通道数和维数理解起来好抽象。
```
/*二维单通道*/
cv::Mat m0(3, 3, CV_8UC1, Scalar(2));
m0 = {2, 2, 2,
      2, 2, 2,
      2, 2 ,2};

/*二维三通道*/
cv::Mat m1(3, 3, CV_8UC3, Scalar(1,2,3));
m1 = {{1,2,3}, {1,2,3}, {1,2,3},
      {1,2,3}, {1,2,3}, {1,2,3},
      {1,2,3}, {1,2,3}, {1,2,3},};
```
### 矩阵表达式
|示例|描述|
|----|----|
|m0 + m1, m0 - m1;|矩阵的加法和减法|
|m0 + s; m0 - s; s + m0; s - m1;|矩阵和单个元素的加减|
|-m0;|矩阵取负| 
|s * m0; m0 * s;|矩阵元素缩放|
|m0.mul( m1 ); m0/m1;|按元素将m0和m1相乘，按元素将m0和m1相除|
|m0 * m1;|m0和m1进行矩阵乘法|
|m0.inv( method );|对m0矩阵求逆(默认使用DECONP_LU)|
|m0.t();|对m0矩阵求转置|
|m0 > m1; m0 >= m1; m0 == m1; <br>m0 <= m1; m 0< m1;|按元素进行比较，返回元素只有0和255的uchar类型矩阵|
|m0 & m1; m0 &#124; m1; m0 ^ m1; ~m0; m0 & s;<br>s & m0; m0 &#124; s; s &#124; m0; m0 ^ s; s ^ m0;|矩阵和矩阵之间或者矩阵和单个元素之间按位进行的逻辑操作
|min(m0,m1); max(m0,m1); min(m0,s);<br>min(s,m0); max(m0,s); max(s,m0);|矩阵和矩阵之间或者矩阵和单个元素之间按元素取最大或最小值
|cv::abs( m0 );|对m0按元素取绝对值|
|m0.cross( m1 ); m0.dot( m1 );|向量叉乘和点乘操作|
|cv::Mat::eye( Nr, Nc, type );<br>cv::Mat::zeros( Nr, Nc, type );<br>cv::Mat::ones( Nr, Nc, type );|用于返回规定类型的N*N矩阵的静态方法|
### 饱和转换
`cv::saturation_cast<>()`
, 
