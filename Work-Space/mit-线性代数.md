# MIT 线性代数 Python

***

##### Reference Link:

- [Github MIT 18.06 线性代数（Linear Algebra）中文笔记](https://github.com/apachecn/18.06-linalg-notes)
- [麻省理工公开课：线性代数](http://open.163.com/special/opencourse/daishu.html)
- [love mit线代笔记](https://love2.io/@ayamefing/doc/mit-linear-algebra-notes)
- [bilibili mit 线性代数](https://www.bilibili.com/video/av15463995?from=search&seid=9044780508596404484)

***

### 1.方程组的几何解释

```python
# 二维矩阵与列向量相乘


# 计算矩阵相乘解
'''
a = [[2, 5], [1, 3]]
x = [[1], [2]]
a * x = ?
'''

# 设定参数
a = [[2, 5], [1, 3]]
x = [[1], [2]]

# 判异
if len(a[0]) == len(x):  # 矩阵a的列数和矩阵x的行数必须相等
    print(True)
else:
    print(False)

# 求解
add = 0
for i in range(len(a)):  # a矩阵行循环
    for j in range(len(x[0])):  # x矩阵列循环
        for z in range(len(a[0])):  # a矩阵列循环
            add += a[i][z] * x[z][j]
print(add)


'''
result

True
19
'''
```

### 3.乘法和逆矩阵

```python
# 矩阵转置


# 定义
matrix = [[1, 3],
          [2, 7],
          [4, 9]]

# 操作
ans = []
for col in range(len(matrix[0])):
    tmp = []
    for row in range(len(matrix)):
        tmp.append(matrix[row][col])
    ans.append(tmp)
del tmp
print(ans)

# 结果
[[1, 2, 4], [3, 7, 9]]
```

### 4.逆矩阵求解

https://blog.csdn.net/u010551600/article/details/81504909

### 4.LU分解

https://blog.csdn.net/ibunny/article/details/79414232

### 5.对称矩阵

```python

# 定义
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

# 判断
if len(matrix) == len(matrix[0]):  # 行数必须等于列数
    print(True)
else:
    print(False)

# 操作
for row in range(len(matrix)):
    for col in range(row + 1, len(matrix[0])):
        matrix[row][col], matrix[col][row] = matrix[col][row], matrix[row][col]
print(matrix)

# 结果
True
[[1, 4, 7], [2, 5, 8], [3, 6, 9]]
```
