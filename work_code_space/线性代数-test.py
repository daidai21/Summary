# -*- coding: utf-8 -*-


'''
二维矩阵与列向量相乘
'''


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
