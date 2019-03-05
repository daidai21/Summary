# Python3

### Base

- `is`和`==`区别
  - Python中对象包含的三个基本要素，分别是：id(身份标识)、type(数据类型)和value(值)
  - `==`是比较值是否相等；`is`是比较id是否相等
- 元类
  - 先定义类，然后创建实例
```python

```
- 静态方法（staticmethod）、类方法（classmethod）和实例方法
```python

```
- 类变量和实例变量
```python

```
- 自省
  - 自省就是面向对象的语言所写的程序在运行时，能知道对象的类型。简单一句就是运行时能够获得对象的类型。比如：`type()`、`dir()`、`getattr()`、`hasattr()`、`isinstance()`
```python
a = [1,2,3]
b = {'a':1,'b':2,'c':3}
c = True
print type(a),type(b),type(c)  # <type 'list'> <type 'dict'> <type 'bool'>
print isinstance(a,list)  # True
```
- 字典推导式
```python

```
- 单下划线`_`和双下划线`__`
```python

```
- 迭代器和生成器
```python
# 迭代器
iter() 和 next()
# 生成器
yield
```
- `*args`和`**kwargs`


- 面向切面编程AOP和装饰器

- 鸭子类型

- 重载

- 新式类和旧式类

- 内存管理

- 垃圾回收机制

- `__new__`和`__init__`的区别

- GIL线程全局锁

- 进程、线程和协程

- 协程

- lambda函数

- 函数式编程

- `copy()`和`deepcopy()`的区别

- 2.和3.的版本差异

- 闭包

- 函数式编程

- `map` 函数和 `reduce` 函数




### Python & C++/C

- SWIG
- ctypes

### Code Style

- PEP8标准
- Python optimize
  - [writing-Solid-Python-Code](https://www.fuweihu.xyz/2018/09/19/writing-Solid-Python-Code/)
  - [Effective-Python](https://www.fuweihu.xyz/2018/09/18/Effective-Python/)
