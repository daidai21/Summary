<center><h1>C++ STL Document</h1></center>

- 仅对面试题的stl用法！

## 通用库

##### I/O库 `<iostream>`

##### 数学函数 `<cstdlib>`

- `abs(n)`  返回n的绝对值
- `pow(a, b)`  返回a的b次方
- `sqrt(n)`  返回n的平方根

##### 字符串库 `<string>`

```cpp
sting str; // 定义str
```

- 容量
  - `str.empty()`  若str为空则返回1，否则返回0
  - `str.size()`  返回str的长度
- 操作
  - `str.clear()`  清除str
  - `str.insert(n, tmp)`  在字符串str的第n位插入tmp
  - `str.erase(begin, end, tmp)`  移除str的begin到end之间的tmp字符
  - `str.push_back(tmp)`  将tmp附加到str结尾
  - `str.pop_back()`  从字符串str移除末尾字符
  - `str.append(tmp)`  后附tmp到str末尾
  - `str.replace(n, num, tmp)`  str从第n字符开始num个字符替换为tmp
- 查找
  - `str.find(tmp, n)`  在str的第n个字符开始搜索tmp，返回首次匹配的位置
  - `str.rfind(tmp, n)`  在str的第n个字符开始搜索tmp，返回最后匹配的位置

## 容器库

##### Vector库 `<vector>`

```cpp
vector<type> vec(n); // 定义vec的类型是type，大小为n
vector<type> vec(n); // 定义vec的类型是type，赋值为1， 2， 3
vector<int> arr(2);
vector<double> arr{1, 2, 3};
```

- 容量
  - `vec.empty()`  如果vec非空则返回0，否则返回1
  - `vec.size()`  返回vec中的元素个数
- 修改器
  - `vec.clear()`  清除vec
  - `vec.insert()`
  - `vec.erase(begin, end)`  移除begin到end中的元素
  - `vec.erase(begin)`  移除begin以后的元素
  - `vec.push_back(tmp)`  将tmp后附到vec尾部
  - `vec.resize(n)`  重置vec可以容纳n和元素

##### Set库 `<set>`

```cpp
set<type> set_;
```

- 容量
  - `set.empty()`  如果set为空返回0，否则返回1
  - `set.size()`  返回集合中元素的个数
- 修改器
  - `set.clear()`  清除set
  - `set.insert(tmp)`  set中插入tmp
  - `set.erase(tmp)`  set中删除tmp
- 查找

```cpp
set<int>::iterator iter;
iter = set.find(tmp); // 在set中查找tmp，找到返回tmp的值
cout << *iter << endl; // 返回值
```

##### Map库 `<map>`

```cpp
map<key-type, value-type> dict; // 定义dict及其键值类型
map<int, string> dict;
```

- 容量
  - `dict.empty()`  如果dict为空返回0，否则返回1
  - `dict.size()`  返回map中元素的个数
- 修改器
  - `dict.clear()`  删除dict
  - `dict.insert(pair<int, string>(key, value))`  在dict中插入key-value
  - `dict.erase(key)`  删除key
- 查找

```cpp
auto search = dict.find(1);
if (search != dict.end()) {
    cout << true << endl;  // 找到，打印1
} else {
    cout << false << endl;  // 未找到，打印0
}
```

## 算法库 `<algorithm>`

##### 排序操作

- `sort(arr.begin(), arr.end());`  对arr进行升序排序

##### 二分搜索操作

- `binary_search(arr.begin(), arr.end(), tmp)`  对已排序序列arr，进行二分查找tmp，找到返回1，否则返回0
