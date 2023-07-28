# cv::Mat类
### 概述
|组成|描述|
|---|---|
|矩阵头|表示它所包含数组类型的元素`flag`<br>表示其维度的元素`dims`<br>表示行和列的数目的元素`rows`和`cols`(dims大于2时无效)
|指针|一个指向数据真正存储位置的`data`指针<br>一个引用计数器`refcount`
|补充|`flag`是int类型，共占32位。<br>0-2位代表depth，3-11代表通道数channels，0-11位共同代表type(如CV_8UC3)。<br>14位代表Mat的内存是否连续。<br>15位代表该Mat是否为某一个Mat的submatrix。<br>16-31位代表magic signature，区分Mat的类型，如Mat和SparseMat。
