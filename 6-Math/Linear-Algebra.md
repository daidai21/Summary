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
    - [ ] 性质 [link](https://zh.wikipedia.org/wiki/%E8%A1%8C%E5%88%97%E5%BC%8F#%E8%A1%8C%E5%88%97%E5%BC%8F%E7%9A%84%E6%80%A7%E8%B3%AA)
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
    - [ ] 初等矩阵
      - [ ] 性质
        - [ ] 行互换
        - [ ] 把某行乘以一非零常数
        - [ ] 把第i行加上第j行的m倍
    - [ ] 分块矩阵(将矩阵分割出较小的矩形矩阵) [link](https://zh.wikipedia.org/wiki/%E5%88%86%E5%A1%8A%E7%9F%A9%E9%99%A3)
      - [ ] 乘法
    - [ ] 可对角化矩阵
    - [ ] 秩
    - [ ] 可对角化矩阵
    - [ ] 埃尔米特矩阵
    - [ ] 奇异值分解
    - [ ] 正定矩阵

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
