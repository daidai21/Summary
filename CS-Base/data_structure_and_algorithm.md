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
# kmp算法
def kmp(string_, pattern_):
    '''
    input:
        string_: 待匹配串
        pattern_: 模板串
    output:
        >= 0: 找到，并返回首次匹配位置
        < 0: 未找到
    '''
    # 计算模板串的部分匹配表
    def pmt(pattern_):
        '''
        input:
            pattern_: 模板串
        output:
            dfa: 部分匹配表数组
        '''
        dfa = []
        for j in range(len(pattern_)):
            max_, tmp = 0, pattern_[:j + 1]
            for i in range(len(tmp)):
                if tmp[:i] == tmp[len(tmp) - i:] and max_ < i:
                    max_ = i
            dfa.append(max_)
        return dfa

    dfa = pmt(pattern_)  # 计算部分匹配表
    j, i, len_string_, len_pattern_ = 0, 0, len(string_), len(pattern_)
    while j < len_string_:
        if string_[j] == pattern_[i]:
            if i == len_pattern_ - 1:
                return j - len_pattern_ + 1
            j, i = j + 1, i + 1
        elif i > 0:  # 状态转移
            i = dfa[i - 1]
        else:
            j += 1
    return -1
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

- Dijkstra

```python
```

- Floyd

```python
```

- Prim

```python
```

- Kruskal

```python
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
