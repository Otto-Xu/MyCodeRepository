C++ pair类型
============
    标准库类型--pair类型在utility头文件中定义
    类模板：template<class T1, class T2> struct pair
    参数：T1是第一个值的数据类型，T2是第二个值的数据类型
    功能：pair将一对值(T1和T2)组合成一个值，这两个值可以具有不同的数据类型，分别用pair的两个公有数据成员first和second访问。
    构造函数：
    pair<T1, T2> p1; 创建一个空的pair对象，它的两个元素分别是T1和T2类型，采用值初始化。
    pair<T1, T2> p1(v1, v2); 创建一个pair对象，它的两个元素分别是T1和T2类型，其中first成员初始化为v1，而second成员初始化为v2。
    make_pair(v1, v2)； 以v1和v2值创建一个新的pair对象，其元素类型分别是v1和v2的类型

#### 1.pair的创建和初始化
pair包含两个数值，与容器一样，pair也是一种模板类型。在创建pair对象时，必须提供两个类型名，两个对应的类型名的类型不必相同。  

```  
pair<string, string> anon;      //创建一个空对象anon，两个元素类型都是string
pair<string, int> word_count;   //创建一个空对象word_count，两个元素类型分别是string和int
pair<string, vector<int>> line; //创建一个空对象line，两个元素类型分别是string和vector<int>
```  
当然也可以在定义时为每个成员提供初始化式：  
```  
pair<string, string> author("James", "Joy");  
pair<string, int> name_age("Tom", 18);
pair<string, int> name_age2(name_age);  //拷贝构造初始化
```  
pair类型的使用相当的繁琐，如果定义多个相同的pair类型对象，可以使用typedef简化声明：  
```  
typedef pair<string, string> Author;  
Author proust("March", "Proust");  
Author Joy("James", "Joy");  
```  
变量间赋值：
```
pair<int, double> p1<1, 1.2>;
pair<int, double> p2 = p1;      
pair<int, double> p3;
p3 = p1;
```
#### 2.pair对象的操作
对于pair类，可以直接访问其数据成员，其成员都是公有的，分别命名为first和second，只需要使用普通的点操作符
```
string firstBook;
if(author.first == "James" && author.second == "Joy")
    firstBook = "Stephen Hero";
```
#### 3.生成新的pair对象
除了构造函数，标准库还定义了一个make_pair函数，由传递给它的两个实参生成一个新的pair对象
```
pair<string, string> next_auth;
string first, last;
while(cin >> first >> last){
    next_auth = make_pair(first, last);
}
```
还可以用下列等价的更复杂的操作:
```
next_auth = pair<string, string>(first, second);
```
由于pair的数据成员是公有的，因而可如下直接地读取输入：
```
pair<string, string> next_auth;
while<cin >> next_auth.first >> next_auth.second>{
    //...
}
```
#### 4.通过tie获取pair元素值
在某些情况函数会以pair对象作为返回值，可以通过std::tie进行接收
```
std::pair<std::string, int> func(){
    return std::make_pair("one", 1);
}

int main(int argc, char *argv[]){
    std::string nums;
    int n;
    
    std::tie(nums, n) = func();
    std::cout << "nums: " << nums << ", n: " << n << std::endl;
    
    return 0;
}
```
