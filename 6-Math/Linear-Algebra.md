# 线性代数

TODO: 行列式计算, 共轭(矩阵), 柯西-施瓦茨不等式

- **向量**
  - 标量(只有大小，没有方向)
  - 向量(<img src="http://latex.codecogs.com/gif.latex?\vec{a} , \vec{AB}, \begin{bmatrix}
a_{11} & a_{12} & a_{13}\\ 
a_{21} & a_{22} & a_{23}
\end{bmatrix}" />, 具有大小和方向)
  - 向量空间 [link](https://zh.wikipedia.org/wiki/%E5%90%91%E9%87%8F%E7%A9%BA%E9%97%B4)
  - 向量投影(<img src="http://latex.codecogs.com/gif.latex?A \bullet B = | A | | B | \cos \theta" />, |A| cos(θ)是A到B的投影)
    - 向量的模(<img src="http://latex.codecogs.com/gif.latex?|a| = \sqrt{v_1^2 + v_2^2 + ... + v_n^2}" />, |a|就是向量a的大小(或称模))
  - 外积(<img src="http://latex.codecogs.com/gif.latex?c = a \otimes b" />, 两个向量的张量积，结果为矩阵(多维空间)) [link](https://zh.wikipedia.org/wiki/%E5%A4%96%E7%A7%AF)
  - 内积(<img src="http://latex.codecogs.com/gif.latex?a \bullet b" />, 又称数量积或标量积, 对应元素乘积的和) [link](https://zh.wikipedia.org/wiki/%E7%82%B9%E7%A7%AF)
  - 向量积(<img src="http://latex.codecogs.com/gif.latex?c = a \times b" />, 又称叉积, c是a和b所在平面的法向量(三维空间))
- **矩阵与行列式**
  - 行列式(<img src="http://latex.codecogs.com/gif.latex?\begin{vmatrix}
a_{11} & a_{12} & a_{13}\\ 
a_{21} & a_{22} & a_{23}
\end{vmatrix}" />, det(A)表示A矩阵的行列式)
    - 性质 [link](https://zh.wikipedia.org/wiki/%E8%A1%8C%E5%88%97%E5%BC%8F#%E8%A1%8C%E5%88%97%E5%BC%8F%E7%9A%84%E6%80%A7%E8%B3%AA)
      - 行列式与它的转置行列式相等
      - 互换行列式的两行(列)，行列式变号
      - 如果行列式有两行(列)完全相同，则此行列式为零
      - 行列式的某一行(列)中所有的元素都乘以同一数k，等于用数k乘此行列式
        - 行列式中某一行(列)的所有元素的公因子可以提到行列式符号的外面
      - 行列式中如果有两行(列)元素成比例，则此行列式等于零
      - 在行列式中，某一行（列）的每个元素是两数之和，则此行列式可拆分为两个相加的行列式
      - 将一行（列）的k倍加进另一行（列）里，行列式的值不变
      - 将行列式的行列互换，行列式的值不变，其中行列互换相当于转置
      - 将矩阵中的每一行每一列上的数都乘以一个常数r, 行列式变为原来的$r^n$倍(<img src="http://latex.codecogs.com/gif.latex?det(AB) = det(A) det(B) , det(rA) = r^ndet(A)" />)
      - 若A是可逆矩阵, <img src="http://latex.codecogs.com/gif.latex?det(A^{-1}) = (det(A))^{-1}" />
  - 矩阵(<img src="http://latex.codecogs.com/gif.latex?\begin{pmatrix}
a_{11} & a_{12} & a_{13}\\ 
a_{21} & a_{22} & a_{23}
\end{pmatrix}" />)
    - 单位矩阵(是一个n乘n的方形矩阵，其主对角线元素为1，其余元素为0)
    - 初等矩阵(一个n阶单位矩阵E经过一次初等行变换或一次初等列变换所得矩阵称为n阶初等矩阵)
    - 方块矩阵(行数及列数皆相同的矩阵)
    - 三角矩阵(上三角矩阵的对角线左下方的系数全部为零，下三角矩阵的对角线右上方的系数全部为零)
    - 分块矩阵(将矩阵分割出较小的矩形矩阵) [link](https://zh.wikipedia.org/wiki/%E5%88%86%E5%A1%8A%E7%9F%A9%E9%99%A3)
    - 矩阵运算
      - 加减法
      - 乘法
      - 数乘
      - 转置
    - 秩(<img src="http://latex.codecogs.com/gif.latex?r(A) , rank(A) , rk(A)" />, 指矩阵中线性无关的行／列向量的最大个数) [link](https://zh.wikipedia.org/wiki/%E7%A7%A9_(%E7%BA%BF%E6%80%A7%E4%BB%A3%E6%95%B0))
    - 矩阵分解(多半将矩阵拆解为数个三角形矩阵)
    - [ ] 特征分解(将矩阵分解为由其特征值和特征向量表示的矩阵之积的方法)
    - [ ] 可对角化矩阵
    - [ ] 埃尔米特矩阵(,又称“自共轭矩阵“，矩阵中每一个第i行第j列的元素都与第j行第i列的元素的共轭相等。)
    - [ ] 奇异值分解(<img src="http://latex.codecogs.com/gif.latex?M = U \sum V^*" />, SVD)
    - [ ] 正定矩阵(,是埃尔米特矩阵中的一种,A是n阶方阵，如果对任何非零向量x，都有$x^TAx>0$，其中$x^T$表示x的转置，就称A正定矩阵。)
      - [ ] 性质
      - 判定方法
        - 求出A的所有特征值。若A的特征值均为正数，则A是正定的；若A的特征值均为负数，则A为负定的。
        - 计算A的各阶主子式。若A的各阶主子式均大于零，则A是正定的；若A的各阶主子式中，奇数阶主子式为负，偶数阶为正，则A为负定的。
    - [ ] 半正定矩阵(,设A是实对称矩阵,如果对任意的实非零列向量x有$x^TAx≥0$，就称A为半正定矩阵。)
      - 若所有特征值均不小于零，则称为半正定。
    - [ ] Hessian矩阵(，是一个由多变量实值函数的所有二阶偏导数组成的方块矩阵)
    - 矩阵的线性运算
      - 加法(对应元素相加)
      - 减法(对应元素相减)
      - 数乘(常数乘矩阵)
      - 乘法(横乘竖, 左矩阵列数等于又矩阵行数)
      - 转置(行列互换)

      - 逆矩阵(<img src="http://latex.codecogs.com/gif.latex?A^{-1}" />)
      - 伴随矩阵(<img src="http://latex.codecogs.com/gif.latex?A^*" />, )

- **线性空间与线性变换**
  - [ ] 格拉姆-施密特正交化 [link](https://zh.wikipedia.org/wiki/%E6%A0%BC%E6%8B%89%E5%A7%86-%E6%96%BD%E5%AF%86%E7%89%B9%E6%AD%A3%E4%BA%A4%E5%8C%96)
  - [ ] 子空间
  - [ ] 基和维数
  - [ ] 基变换
  - [ ] 行空间和列空间
  - [ ] 线性变换
  - [ ] 正交(两向量内积为0) [link](https://zh.wikipedia.org/wiki/%E6%AD%A3%E4%BA%A4)
  - [ ] 最小二乘
  - [ ] 特征向量(<img src="http://latex.codecogs.com/gif.latex?Av = \lambda v" />, 矩阵A的特征向量$v$经过$\lambda$线性变换后与原来的$v$保持在同一条直线上) [link](https://zh.wikipedia.org/wiki/%E7%89%B9%E5%BE%81%E5%80%BC%E5%92%8C%E7%89%B9%E5%BE%81%E5%90%91%E9%87%8F)

- other
  - 范德蒙矩阵(<img src="http://latex.codecogs.com/gif.latex?\prod" />)

- 克莱姆法则
- [ ] 范数
  - L0(,向量中非零元素的个数)
  - L1(,向量中每个元素绝对值的和)
  - L2(,即欧氏距离,为向量各元素平方和的开方)
- 距离
  - 曼哈顿距离(<img src="http://latex.codecogs.com/gif.latex?d(i, j) = |x_1 - x_2| + |y_1 - y_2|" />,)
  - 欧式距离(,又称欧几里得距离)
  - 闵可夫斯距离
  - 切比雪夫距离
  - 夹角余弦
  - 汉明距离
  - 杰卡德相似系数
  - 杰卡德距离
- 二次型的定义
- 线性方程组的数值解法，尤其是共轭梯度法
- 对称矩阵
- 主成分分析（PCA）
- LU 分解


***

- [ ] 主子式
- [ ] 顺序主子式
- [ ] 余子式
- [ ] 代数余子式

- [ ] 稀疏矩阵(, 在矩阵中，若数值为0的元素数目远远多于非0元素的数目，并且非0元素分布没有规律时，则称该矩阵为稀疏矩阵)
  - [ ] 优点
    - 计算快
  - [ ] 缺点
    - 空间复杂度  0值 占用大量内存
    - 时间复杂度
- [ ] 稠密矩阵(,在矩阵中，若非0元素数目占大多数时，则称该矩阵为稠密矩阵)
