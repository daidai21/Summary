记录传统机器学习的工作流程中的数学原理和实例代码。算是《机器学习》--周志华的总结

# 1 - 特征工程

## 1.1 - 数据预处理

- 不属于同一量纲：即特征的规格不一样，不能够放在一起比较。无量纲化可以解决这一问题。
- 信息冗余：对于某些定量特征，其包含的有效信息为区间划分，例如学习成绩，假若只关心“及格”或不“及格”，那么需要将定量的考分，转换成“1”和“0”表示及格和未及格。二值化可以解决这一问题。
- 定性特征不能直接使用：某些机器学习算法和模型只能接受定量特征的输入，那么需要将定性特征转换为定量特征。最简单的方式是为每一种定性值指定一个定量值，但是这种方式过于灵活，增加了调参的工作。通常使用哑编码的方式将定性特征转换为定量特征：假设有N种定性值，则将这一个特征扩展为N种特征，当原始特征值为第i种定性值时，第i个扩展特征赋值为1，其他扩展特征赋值为0。哑编码的方式相比直接指定的方式，不用增加调参的工作，对于线性模型来说，使用哑编码后的特征可达到非线性的效果。
- 存在缺失值：缺失值需要补充。
- 信息利用率低：不同的机器学习算法和模型对数据中信息的利用是不同的，之前提到在线性模型中，使用对定性特征哑编码可以达到非线性的效果。类似地，对定量变量多项式化，或者进行其他的转换，都能达到非线性的效果。

### 1.1.1 - 无量纲化

- 无量纲化使不同规格的数据转换到同一规格。常见的无量纲化方法有标准化和区间缩放法。标准化的前提是特征值服从正态分布，标准化后，其转换成标准正态分布。区间缩放法利用了边界值信息，将特征的取值区间缩放到某个特点的范围，例如[0, 1]等。

#### 1.1.1.1 - 标准化

- 标准化需要计算特征的均值和标准差，公式表达为：
<div align="center"><img src="https://latex.codecogs.com/gif.latex?x' = \frac{x - \bar{X}}{S}"></div>

- Example-Code:

```python
```

#### 1.1.1.2 - 区间缩放法

- 区间缩放法的思路有多种，常见的一种为利用两个最值进行缩放，公式表达为：
<div align="center"><img src="https://latex.codecogs.com/gif.latex?x' = \frac{x - Min}{Max -Min}"></div>

- Example-Code:

```python
```

#### 1.1.1.3 - 标准化与归一化的区别

- 简单来说，标准化是依照特征矩阵的列处理数据，其通过求z-score的方法，将样本的特征值转换到同一量纲下。归一化是依照特征矩阵的行处理数据，其目的在于样本向量在点乘运算或其他核函数计算相似性时，拥有统一的标准，也就是说都转化为“单位向量”。规则为l2的归一化公式如下：
<div align="center"><img src="https://latex.codecogs.com/gif.latex?x' = \frac{x}{\sqrt{\sum_j^mx[j]^2]}}"></div>

- Example-Code:

```python
```

### 1.1.2 - 对定量特征二值化

- 定量特征二值化的核心在于设定一个阈值，大于阈值的赋值为1，小于等于阈值的赋值为0，公式表达如下：
<div align="center"><img src="https://latex.codecogs.com/gif.latex?x' =\left\{\begin{matrix}
1, &  x > threshold \\ 
0, & x \leqslant  threshold
\end{matrix}\right."></div>

- Example-Code:

```python
```

### 1.1.3 - 对定性特征哑编码

- 由于IRIS数据集的特征皆为定量特征，故使用其目标值进行哑编码（实际上是不需要的）。使用preproccessing库的OneHotEncoder类对数据进行哑编码的代码如下：
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

### 1.1.4 - 缺失值计算

- 由于IRIS数据集没有缺失值，故对数据集新增一个样本，4个特征均赋值为NaN，表示数据缺失。使用preproccessing库的Imputer类对数据进行缺失值计算的代码如下：
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

### 1.1.5 - 数据变换

- 常见的数据变换有基于多项式的、基于指数函数的、基于对数函数的。4个特征，度为2的多项式转换公式如下：
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

- 基于单变元函数的数据变换可以使用一个统一的方式完成，使用preproccessing库的FunctionTransformer对数据进行对数函数转换的代码如下：

- Example-Code:

```python
```
## 1.2 - 特征选择

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

### 1.2.1 - 过滤式选择(Filter)

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

#### 1.2.1.1 - 方差选择法

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

#### 1.2.1.2 - 相关系数法

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

#### 1.2.1.3 - 卡方检验

- 经典的卡方检验是检验定性自变量对定性因变量的相关性。假设自变量有N种取值，因变量有M种取值，考虑自变量等于i且因变量等于j的样本频数的观察值与期望的差距，构建统计量：
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

#### 1.2.1.4 - 互信息和最大信息系数

- 经典的互信息也是评价定性自变量对定性因变量的相关性的，互信息计算公式如下：
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

#### 1.2.1.5 - Pearson相关系数

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

#### 1.2.1.6 - 距离相关系数

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

### 1.2.2 - 包裹式选择(Wrapper)

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

#### 1.2.2.1 - 递归特征消除法

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


#### 1.2.2.2 - 前向搜索

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


#### 1.2.2.3 - 后向搜索

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


### 1.2.3 - 嵌入式选择(Embedded)

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


#### 1.2.3.1 - 基于惩罚项的特征选择法

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


#### 1.2.3.2 - 基于树模型的特征选择法

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


#### 1.2.3.3 - 基于学习模型的特征排序

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


# 2 - 数据降维

### 2.1 - 主成分分析PCA

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


### 2.2 - 线性判别分析LDA

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


### 2.3 - 奇异值分解SVD

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


# 3 - 模型选择


## 3.1 - 正则化

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

## 3.2 - 模型训练

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

## 3.3 - 交叉验证

<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

# 4 - 模型评估



## 4.1 - 偏差与方差
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```


## 4.2 - 判别模型与生成模型
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

## 4.3 - 评估指标
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>

- Example-Code:

```python
```

# 5 - 具体学习模型对比
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>


- Example-Code:


```python
```

传统机器学习主要算法模型对比

[scikit-learn 小抄](https://scikit-learn.org/stable/tutorial/machine_learning_map/index.html)

# 6 - 集成学习

- 链接
  - https://www.cnblogs.com/jasonfreak/p/5657196.html
  - https://www.jiqizhixin.com/articles/2018-12-28-11?from=synced&keyword=%E9%9B%86%E6%88%90%E5%AD%A6%E4%B9%A0

## 6.1 - 装袋 （Bagging）

分类：简单投票
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>


- Example-Code:


```python
```

回归：简单平均
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>


- Example-Code:


```python
```

## 6.2 - 提升 （Boosting）
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>


- Example-Code:


```python
```

## 6.3 - 堆叠 （Stacking）
<div align="center"><img src="https://latex.codecogs.com/gif.latex?"></div>


- Example-Code:


```python
```

## 6.4 - 对比

|  | Bagging | Boosting | Stacking |
| :-: | :-: | :-: | :-: |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |

# 综合参考链接

- [使用sklearn做单机特征工程](https://www.cnblogs.com/jasonfreak/p/5448385.html)
- [鱼遇雨欲语与余 | 武汉大学](https://www.zhihu.com/people/wang-he-13-93/activities)
