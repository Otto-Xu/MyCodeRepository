# cv::Mat类
### 概述
|组成|描述|
|---|---|
|矩阵头|表示它所包含数组类型的元素`flag`<br>表示其维度的元素`dims`<br>表示行和列的数目的元素`rows`和`cols`(dims大于2时无效)
|指针|一个指向数据真正存储位置的`data`指针<br>一个引用计数器`refcount`
|补充|`flag`是int类型，共占32位。<br>0-2位代表depth，3-11代表通道数channels，0-11位共同代表type(如CV_8UC3)。<br>14位代表Mat的内存是否连续。<br>15位代表该Mat是否为某一个Mat的submatrix。<br>16-31位代表magic signature，区分Mat的类型，如Mat和SparseMat。
  
cv::Mat中的元素可以是一个简单的数字，也可以是多个数字。在包含多个数字的时候，它就被称为“多通道数组”
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
### 数组迭代器NAryMatlterator


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
### 成员函数
|示例|描述|
|----|----|
|m1 = m0.clone();| Make a complete copy of m0, copying all data elements as well; cloned array will be continuous|
|m0.copyTo( m1 );| Copy contents of m0 onto m1, reallocating m1 if necessary (equivalent to m1=m0.clone())|
|m0.copyTo( m1, mask);|Same as m0.copyTo(m1), except only entries indicated in the array mask are copied|
|m0.convertTo(m1, type, scale,offset);|Convert elements of m0 to type (e.g., CV_32F) and write to m1 after scaling by scale (default 1.0)and adding offset (default0.0)|
|m0.assignTo( m1, type);|Internal use only (resembles convertTo)|
|m0.setTo( s, mask );| Set all entries in m0 to singleton value s; if mask is present, set only those values corresponding to nonzero elements in mask|
|m0.reshape( chan,rows );|Changes effective shape of a two-dimensional matrix; chan or rows may be zero, which implies “no change”; data is not copied|
|m0.push_back( s );| Extend an m × 1 matrix and insert the singleton s at the end|
|m0.push_back( m1 );| Extend an m × n by k rows and copy m1 into those rows; m1 must be k × n|
|m0.pop_back( n );| Remove n rows from the end of an m × n (default value of n is 1)|
|m0.locateROI( size,offset );| Write whole size of m0 to cv::Size size; if m0 is a “view” of a larger matrix, write location of starting corner to Point& offset|
|m0.adjustROI( t, b,l, r );|Increase the size of a view by t pixels above, b pixels below, l pixels to the left, and r pixels to the right|
|m0.total();| Compute the total number of array elements (does not include channels)|
|m0.isContinuous();| Return true only if the rows in m0 are packed without space between them in memory|
|m0.elemSize();| Return the size of the elements of m0 in bytes (e.g., a three-channel float matrix would return 12 bytes)|
|m0.elemSize1();| Return the size of the subelements of m0 in bytes (e.g., a three-channel float matrix would return 4 bytes)|
|m0.type();| Return a valid type identifier for the elements of m0 (e.g., CV_32FC3)|
|m0.depth();| Return a valid type identifier for the individial channels of m0 (e.g., CV_32F)|
|m0.channels();| Return the number of channels in the elements of m0|
|m0.size();| Return the size of the m0 as a cv::Size object|
|m0.empty();| Return true only if the array has no elements (i.e., m0.total==0 or m0.data==NULL)|  

# cv::SparseMat类
### 概述
稀疏矩阵  
```
[  
	0, 0, 0, 0,  
	0, 5, 0, 3,  
	2, 0, 0, 0,  
	0, 7, 2, 0  
]
```
cv::SparseMat在很多方面都类似于cv::Mat，但是它们数据德组织方式有非常大的不同，cv::Mat使用的接近C风格的数组，cv::SparseMat使用哈希表来存储非0元素。
### 访问稀疏矩阵中的元素
```
cv::SparseMat::ptr();
cv::SparseMat::ref();
cv::SparseMat::value();
cv::SparseMat::find();
```
### 稀疏数组中的特有函数
|示例|描述|
|----|----|
|cv::SparseMat sm;| Create a sparse matrix without initialization|
|cv::SparseMat sm( 3, sz, CV_32F );|Create a three-dimensional sparse matrix with dimensions given by the array sz of type float|
|cv::SparseMat sm( sm0 );| Create a new sparse matrix that is a copy of the existing sparse matrix sm0|
|cv::SparseMat( m0, try1d );| Create a sparse matrix from an existing dense matrix m0; if the bool try1d is true, convert m0 to a one-dimensional sparse matrix if the dense matrix was n × 1 or 1 × n|
|cv::SparseMat(&old_sparse_mat );|Create a new sparse matrix from a pointer to a pre–version 2.1 C-style sparse matrix of type CvSparseMat|
|CvSparseMat* old_sm =(cv::SparseMat*) sm;|Cast operator creates a pointer to a pre–version 2.1 C-style sparse matrix; that CvSparseMat object is created and all data is copied into it, and then its pointer is returned|
|size_t n = sm.nzcount(); |Return the number of nonzero elements in sm|
|size_t h = sm.hash( i0 );<br>size_t h = sm.hash( i0, i1);<br>size_t h = sm.hash( i0, i1, i2 );<br>size_t h = sm.hash( idx );|Return the hash value for element i0 in a one-dimensionalsparse matrix; i0, i1 in a two-dimensionalsparse matrix; i0, i1, i2 in a three-dimensional sparse matrix; or the element indicated by the array of integers idx in an n-dimensionalsparse matrix|
|sm.ref<float>( i0 ) = f0;<br>sm.ref<float>( i0, i1 ) = f0;<br>sm.ref<float>( i0, i1, i2 ) = f0;<br>sm.ref<float>( idx ) = f0;|Assign the value f0 to element i0 in a one-dimensionalsparse matrix; i0, i1 in a two-dimensionalsparse matrix; i0, i1, i2 in a three-dimensional sparse matrix; or the element indicated by the array of integers idx in an n-dimensionalsparse matrix|
|f0 = sm.value<float>( i0 );<br>f0 = sm.value<float>( i0, i1);<br>f0 = sm.value<float>( i0, i1, i2 );<br>f0 = sm.value<float>( idx );|Assign the value to f0 from element i0 in a one-dimensionalsparse matrix; i0, i1 in a two-dimensionalsparse matrix; i0, i1, i2 in a three-dimensional sparse matrix; or the element indicated by the array of integers idx in an n-dimensionalsparse matrix|
|p0 = sm.find<float>( i0 );<br>p0 = sm.find<float>( i0, i1);<br>p0 = sm.find<float>( i0, i1, i2 );<br>p0 = sm.find<float>( idx );|Assign to p0 the address of element i0 in a one-dimensionalsparse matrix; i0, i1 in a two-dimensionalsparse matrix; i0, i1, i2 in a three-dimensional sparse matrix; or the element indicated by the array of integers idx in an n-dimensionalsparse matrix|
|sm.erase( i0, i1, &hashval);<br>sm.erase( i0, i1, i2, &hashval );<br>sm.erase( idx, &hashval );|Remove the element at (i0, i1) in a two-dimensionalsparse matrix; at (i0, i1, i2) in a three-dimensionalsparse matrix; or the element indicated by the array of integers idx in an n-dimensional sparse matrix. If hashval is not NULL, use the provided value instead of computing it|
|cv::SparseMatIterator<float> it = sm.begin<float>();|Create a sparse matrix iterator it and point it at the first value of the floating-point array sm
|cv::SparseMatIterator<uchar> it_end = sm.end<uchar>();|Create a sparse matrix iterator it_end and initialize it to the value succeeding the final value in the byte array sm|

# 为大型数组准备的模板结构
```
cv::Mat_<>
cv::SparseMat_<>
```
