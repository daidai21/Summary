# Data Structure And Algorithm

### Overview

- Brush Problem Link
  - [Nowcoder](https://www.nowcoder.com/)
    - [剑指offer](https://www.nowcoder.com/ta/coding-interviews)
    - ... ...
  - [Leetcode-cn](https://leetcode-cn.com/)

### Data Structure

##### 数组
##### 字符串

```python
'''
KMP 算法
'''
#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 计算模板串部分匹配表
vector<int> pmt(string pat) {
    vector<int> dfa;
    for (int j = 0; j < pat.size(); j++) {
        int max = 0;
        for (int i = 0; i < j + 1; i++) {
            vector<string> start, end;
            for (int n = 0; n < i; n++) {
                string tmp;
                tmp = pat[n];
                start.push_back(tmp);
                tmp = pat[j + 1 - i];
                end.push_back(tmp);
            }
            if (start == end && max < i) {
                max = i;
            }
        }
        dfa.push_back(max);
    }
    return dfa;
}

// kmp 算法
int kmp(string str, string pat) {
    vector<int> dfa = pmt(pat); // 计算部分匹配表
    int j, i = 0;
    int len_str = str.size();
    int len_pat = pat.size();
    while (j < len_str) {
        if (str[j] == pat[i]) {
            if (i == len_pat - 1) {
                return j - len_pat + 1;
            }
            j++;
            i++;
        } else if (i > 0) { // 状态转移
            i = dfa[i - 1];
        } else {
            j++;
        }
    }
    return -1;
}


// 主函数
int main() {
    string str = "123234562476qvregerv";
    string pat = "76qv";
    cout << kmp(str, pat) << endl;
    return 0;
}
```

##### 链表

```python
插入
查找
删除
求长
```

##### 栈

```python
数组实现
链表实现

```

##### 队列

```python
数组实现
链表实现

```

##### 哈希

```python
```

##### 堆

```python
```

##### 树


##### 图

- BFS
- DFS

- A*搜索算法

```python
'''
Dijkstra 算法
'''
```

```python
'''
Floyd 算法
'''
```

```python
'''
Prim 算法
'''
```

```python
'''
Kruskal 算法
'''
```

### Algorithm

##### 查找
##### 排序
。。。


### Classical Algorithm Idea

- 回溯法 Backtracking 
- 动态规划 Dynamic Programming 

### Other Classical Algorithm

- 

### Interview Classical Problem



***


### Boss Said

内排序 外排序
快排 三路快排
希尔
归并 三相归并
堆排序
b b+树 平衡
二分查找 多分查找
背包九讲
dp 二次dp
    注意使用范围
回溯
分支限界
蒙特卡罗
