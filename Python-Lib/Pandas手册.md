# Pandas 手册

**这个不是全部API，而是大部分常用的，详细的API介绍还是移步[官网](http://pandas.pydata.org/pandas-docs/stable/)**

### 数据结构

- 系列(Series) | 1维 | 大小不变
- 数据帧(DataFrame) | 2维 | 大小可变的表结构与潜在的异质类型的列
- 面板(Panel) | 3维 | 大小可变数组

### 系列

- `s = pd.Series(data=ndarray/list/constants, index, dtype, copy=false/true)`  创建

### 数据帧

- `pandas.DataFrame(data=ndarray/series/map/lists/dict/constant/DataFrame, index, columns, dtype, copy=false/true)`  创建
- `df['col']`  列选择
- `df['col'] = df['col_1'] + df['col_2']`  列添加
- `del df['col']` 或者 `df.pop('col')`  列删除
- `df.loc('index')`  行选择 按标签
- `df.iloc[col_index_num]`  行选择 按整数位置
- `df[start:end]`  行切片
- `df.append(df_tmp)`  附加行
- `df.drop(row_index_num)`  删除行

### 面板

- `pandas.Panel(data=ndarray/series/map/lists/dict/constant/DataFrame, items=0, major_axis=1, minor_axis=2, dtype, copy=false/true)`  创建（items：每个项目对应于内部包含的数据帧(DataFrame)；major_axis：它是每个数据帧(DataFrame)的索引(行)；minor_axis：它是每个数据帧(DataFrame)的列。）
- `p['df_num']`  选择数据 使用Item
- `p.major_axis(row_num)`  选择数据 行
- `p.minor_axis(col_num)`  选择数据 列

### 基本功能

- 系列
  - `s.axes`  返回系列的标签列表
  - `s.dtype`  返回对象的数据类型
  - `s.empty`  返回布尔值，True表示对象是否为空
  - `s.ndim`  返回对象的维数
  - `s.size`  返回系列的长度
  - `s.values`  以数组形式返回系列中的实际数据值
  - `s.head(n)`  返回前n行
  - `s.tail(n)`  返回最后n行
- 数据帧
  - `df.T`  转置行和列
  - `df.axes`  返回行轴标签和列轴标签列表
  - `df.dtypes`  返回每列的数据类型
  - `df.empty`  返回布尔值，True表示对象是否为空
  - `df.ndim`  返回对象的维数
  - `df.shape`  返回表示维度的元组
  - `df.size`  返回元素数
  - `df.values`  将实际数据作为NDarray返回
  - `df.head(n)`  返回前n行
  - `df.tail(n)`  返回最后n行
- 描述性统计
  - `df.sum(axis_n)`  返回所请求轴的值的总和
  - `df.mean()`  返回平均值
  - `df.std()`  返回数字列的Bressel标准偏差
  - `df.count()`  返回非空观测数量
  - `df.median()`  返回所有值的中位数
  - `df.mode()`  返回值的模值
  - `df.min()`  返回所有值中的最小值
  - `df.max()`  所有值中的最大值
  - `df.abs()`  返回绝对值
  - `df.prod()`  返回数组元素的乘积
  - `df.cumsum()`  返回累计总和
  - `df.cumprod()`  返回累计乘积
  - `df.describe(include='object/number/all')`  返回有关列的统计信息的摘要（object：汇总字符串列；number：汇总数字列；all：将所有列汇总在一起。）

### 函数引用

- `df.pipe()`  表格函数应用：可以通过将函数和适当数量的参数作为管道参数来执行自定义操作
- `df.apply()`  行或列合理函数应用
- `df.applymap()`  元素合理函数应用

### 重建索引

- `df.reindex(df_tmp, method='ffill/backfill/nearest', limit=n)`  重建索引
- `df.rename(inplace=False/True)`  重命名：方法允许基于一些映射(字典或者系列)或任意函数来重新标记一个轴

### 迭代

- `df.iteritems()`  迭代(key，value)对
- `df.iterrows()`  将行迭代为(索引，系列)对
- `df.itertuples()`  以namedtuples的形式迭代行

### 排序

- `df.sort_index(axis=0/1, ascending=True/False)`  按标签排序
- `df.sort_values(by, kind='mergeesort/heapsort/quicksort')`  按值排序（by列名称；kind排序算法）

### 字符串和文本数据

- `lower()`  将Series/Index中的字符串转换为小写
- `upper()`  将Series/Index中的字符串转换为大写
- `len()`  计算字符串长度
- `strip()`  帮助从两侧的系列/索引中的每个字符串中删除空格(包括换行符)
- `split(' ')`  用给定的模式拆分每个字符串
- `cat(sep=' ')`  使用给定的分隔符连接系列/索引元素
- `get_dummies()`  返回具有单热编码值的数据帧(DataFrame)
- `contains(pattern)`  如果元素中包含子字符串，则返回每个元素的布尔值True，否则为False
- `replace(a,b)`  将值a替换为值b
- `repeat(value)`  重复每个元素指定的次数
- `count(pattern)`  返回模式中每个元素的出现总数
- `startswith(pattern)`  如果系列/索引中的元素以模式开始，则返回true
- `endswith(pattern)`  如果系列/索引中的元素以模式结束，则返回true
- `find(pattern)`  返回模式第一次出现的位置
- `findall(pattern)`  返回模式的所有出现的列表
- `swapcase`  变换字母大小写
- `islower()`  检查系列/索引中每个字符串中的所有字符是否小写，返回布尔值
- `isupper()`  检查系列/索引中每个字符串中的所有字符是否大写，返回布尔值
- `isnumeric()`  检查系列/索引中每个字符串中的所有字符是否为数字，返回布尔值

### 选项和自定义

- `pd.get_option(param='display.max_rows/display.max_columns')`  需要一个参数，并返回下面输出中给出的值
- `pd.set_option(param='display.max_rows/display.max_columns', value)`  需要两个参数，并将该值设置为指定的参数值
- `pd.reset_option(param='display.max_rows/display.max_columns')`  接受一个参数，并将该值设置为默认值
- `pd.describe_option(param='display.max_rows/display.max_columns')`  打印参数的描述
- `pd.option_context()`  上下文管理器用于临时设置语句中的选项
- 常用参数：
  - `display.max_rows`  要显示的最大行数
  - `display.max_columns`  要显示的最大列数
  - `display.expand_frame_repr`  显示数据帧以拉伸页面
  - `display.max_colwidth`  显示最大列宽
  - `display.precision`  显示十进制数的精度

### 索引和选择数据

- `df.loc['row_start':'row_end', 'col_start':'col_end']`  完成基于标签的索引
- `df.iloc[row_start:row_end, col_start:col_end]`  获得纯整数索引
- `df.ix[row_start:row_end, col_start:col_end]`  运算符进行选择和子集化对象的混合方法
- 使用符号
  - `s.loc[indexer]`  Series
  - `df.loc[row_index,col_index]`  DataFrame
  - `p.loc[item_index,major_index, minor_index]`  Panel
- `df.index`  属性访问（可以使用属性运算符.来选择列）

### 统计函数

- `df.pct_change()`  将每个元素与其前一个元素进行比较，并计算变化百分比
- `df.cov(df_tmp)`  协方差
- `df.corr()`  相关性（相关性显示了任何两个数值(系列)之间的线性关系）
- `s.rank()`  数据排名

### 窗口函数

- `df.rolling(window=n)`  n窗口大小的统计值（后加句点式统计函数）
- `df.expanding(min_periods=n)`  n窗口大小的统计值（累计计算）
- `df.ewm(com, span, halflife)`  n窗口大小的统计值

### 缺失数据

- `df.isnull()`  检查缺失值，为空返回True
- `df.notnull()`  检查缺失值，不为空返回True
- 在求和数据时，NA将被视为0
- `df.fillna(n)`  用标量值n替换NaN
- `df.fillna(method='fill/backfill')`  填写NA前进和后退（fill填充方法向前；backfill填充方法向后）

### 分组

- `obj.groupby(‘key’)` 或 `obj.groupby([‘key1’,’key2’])` 或 `obj.groupby(key,axis=1)`  将数据拆分成组
- `df.get_group('')`  选择一个分组
- `df_group.transform(lambda)`  转换（分组或列上的转换返回索引大小与被分组的索引相同的对象）
- `df.groupby('').filter(lambda_func)`  过滤（过滤根据定义的标准过滤数据并返回数据的子集）

### 合并/拼接

- `pd.merge(left, right, how='inner/outer/left/right', on=None, left_on=None, right_on=None,
left_index=False, right_index=False, sort=True)`  （left一个DataFrame对象；right另一个DataFrame对象；on列(名称)连接，必须在左和右DataFrame对象中存在(找到)；left_on左侧DataFrame中的列用作键，可以是列名或长度等于DataFrame长度的数组；right_on 来自右的DataFrame的列作为键，可以是列名或长度等于DataFrame长度的数组；left_index如果为True，则使用左侧DataFrame中的索引(行标签)作为其连接键；how是left, right, outer以及inner之中的一个，默认为内inner；sort照字典顺序通过连接键对结果DataFrame进行排序）

### 级联

- `pd.concat(objs, axis=0, join='outer/inner', join_axes=None, ignore_index=False)`  连接对象（objs是Series，DataFrame或Panel对象的序列或映射；axis是连接的轴；join如何处理其他轴上的索引；join_axes是Index对象的列表；ignore_index是否使用连接轴上的索引值）
- `df.append(df_tmp)`  使用附加连接
- `pd.datetime.now()`  获取当前的日期和时间
- `pd.date_range("start", "end", freq="").time`  创建一个时间范围
- `pd.to_datetime()`  转换为时间戳

### 日期功能

- `pd.date_range('data', periods=n, freq='')`  创建一个日期范围（freq更改日期频率）
- 偏移别名 略

### 时间差

- `pd.Timedelta('')`  是时间上的差异，以不同的单位来表示

### 分类数据

- `pandas.Categorical(values, categories, ordered)`  分类构造函数
- `s.categories`  获取对象的类别
- `obj.ordered`  获取对象的顺序
- `s.cat.categories`  重命名类别
- `Categorical.add.categories()`  附加新类别
- `Categorical.remove_categories()`  删除类别
- 当ordered==True和类别是相同时，所有比较(\==，!=，>，>=，<，和<=)分类数据到另一个分类系列  分类数据的比较

### 可视化

- `df.plot()`  绘图
- `df.plot.bar(stacked=False/True)`  竖直条形图
- `df.plot.barh(stacked=True)`  水平条形图
- `df.plot.hist(bins=n)`  直方图
- `df.plot.box()`  箱型图
- `df.plot.area()`  区域块图
- `df.plot.scatter(x='a', y='b')`  散点图形
- `df.plot.pie(subplots=True)`  饼状图

### IO工具

- `pd.read_csv(index_col=['col_index'], dtype={'col_name': dtype}, names=['name'], skiprows=n)`  从csv文件中读取数据并创建一个DataFrame对象（dtype转换器；使用names参数指定标题的名称；skiprows跳过指定的行数）

### 稀疏数据

- `s.to_sparse()`  稀疏Dtypes（稀疏数据应该具有与其密集表示相同的dtype；支持float64，int64和booldtypes）

### 链接

- [Pandas 官方文档](http://pandas.pydata.org/pandas-docs/stable/api.html)
- [莫凡Python | pandas](https://morvanzhou.github.io/tutorials/data-manipulation/np-pd/1-1-why/)
- [易百教程 | Pandas教程](https://www.yiibai.com/pandas/python_pandas_environment_setup.html)
- [Pandas 中文文档](https://www.pypandas.cn/)
- [pandas:强大的Python数据分析工具包](https://apachecn.github.io/pandas-doc-zh/)
