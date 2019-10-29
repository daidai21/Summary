# <<剑指offer>> with Python

## 二维数组中的查找

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

```python
# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        if len(array) == 0:
            return False
        for row in range(len(array)):
            for col in range(len(array[0])):
                if array[row][col] == target:
                    return True
        return False
```

## 替换空格

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

```python
# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        s_ = list(s)
        for i in range(len(s_)):
            if s_[i] == ' ':
                s_[i] = '%20'
        return ''.join(s_)
```

## 从尾到头打印链表

输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        list_ = []
        while listNode:
            list_.append(listNode.val)
            listNode = listNode.next
        return list_[::-1]
```

## 重建二叉树

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

- 补充基础：
    - 前序遍历：根、左子树、右子树
    - 中序遍历：左子树、根、右子树
- 思路：
    - 首先，寻找根节点就是前序遍历的第一个节点
    - 中序遍历找到根节点的位置，根节点位置的左边是根节点的左子树，右节点是根节点的右子树
    - 中序遍历中的第二个节点就是根节点的左子树，再次回到中序遍历序列找到次根节点的左右子树
    - 不断递归

```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        if len(pre) == 0:
            return
        if len(tin) == 0:
            return
        else:
            res = TreeNode(pre[0])
            res.left = self.reConstructBinaryTree(pre[1:tin.index(pre[0]) + 1], tin[:tin.index(pre[0])])
            res.right = self.reConstructBinaryTree(pre[tin.index(pre[0]) + 1:], tin[tin.index(pre[0]) + 1:])
        return res
```

## 用两个栈实现队列

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

```python
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack_1 = []
        self.stack_2 = []

    def push(self, node):
        # write code here
        self.stack_1.append(node)

    def pop(self):
        # return xx
        if len(self.stack_2) != 0:
            return self.stack_2.pop()
        while self.stack_1:
            self.stack_2.append(self.stack_1.pop())
        return self.stack_2.pop()
```

## 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

- 无脑遍历操作：
```python
# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if len(rotateArray) == 0:
            return 0
        array_min = 0
        for i, item in enumerate(rotateArray):
            if rotateArray[array_min] > item:
                array_min = i
        return rotateArray[array_min]
```
- 调库操作
```python
# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        return min(rotateArray)
```
- 二分：(用时最少)
```python
# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if rotateArray is []:
            return 0
        left, right = 0, len(rotateArray) - 1
        while left <= right:
            mid = int((left + right) / 2)
            if rotateArray[mid] < rotateArray[mid-1]:
                return rotateArray[mid]
            if rotateArray[mid] >= rotateArray[right]:  # between mid and right
                left = mid + 1
            else:  # between left and mid
                right = mid - 1
        return rotateArray[mid]
```

## 斐波那契数列


大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39

- 非递归：
```python
# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        n_1, n_2 = 1, 1
        for _ in range(n - 2):
            n_2, n_1 = n_1 + n_2, n_2
        return n_2
```
- 数组存储：
```python
# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        tmp = [1, 1]
        for _ in range(n - 2):
            tmp.append(tmp[-1] + tmp[-2])
        return tmp[-1]
```
- 递归版：
```python
# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if n == 0:
            return 0
        elif n == 1 or n == 2:
            return 1
        else:
            return self.Fibonacci(n - 1) + self.Fibonacci(n - 2)
```

## 跳台阶

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

- 思想：
    - $dp(n) = dp(n - 1) + dp(n - 2)$
    - 跳上第n阶台阶，就是先跳上n-2阶台阶然后一次跳2阶 和 先跳上n-1阶台阶然后一次跳1阶 取和

```python
# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        # write code here
        if number == 0:
            return 0
        if number == 1 or number == 2:
            return number
        tmp = [1, 2]
        for _ in range(number - 2):
            tmp.append(tmp[-1] + tmp[-2])
        return tmp[-1]
```

## 变态跳台阶

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

- 思想：
    - $dp(n) = dp(n - 1) + dp(n - 2) + ··· + dp(1) + 1$，即：$dp(n) = \sum_{i=1}^{i = n}dp(n) + 1$
    - 跳n阶台阶就是之前所有跳n-i阶然后在跳i阶 和 直接跳n阶台阶 取和

```python
# -*- coding:utf-8 -*-
class Solution:
    def jumpFloorII(self, number):
        # write code here
        if number == 1 or number == 2:
            return number
        tmp = [1, 2]
        for _ in range(number - 2):
            sum_ = 0
            for i, item in enumerate(tmp):
                sum_ += item
            tmp.append(sum_ + 1)
        return tmp[-1]
```

## 矩形覆盖

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

```python
# -*- coding:utf-8 -*-
class Solution:
    def rectCover(self, number):
        # write code here
        if number == 0 or number == 1 or number == 2:
            return number
        tmp = [1, 2]
        for i in range(number - 2):
            tmp.append(tmp[-1] + tmp[-2])
        return tmp[-1]
```

## 二进制中1的个数

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

- 补充基础：
    - 补码：正数的补码就是其本身；负数的补码是在其反码的基础上+1
- 常规：
```python
# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1(self, n):
        # write code here
        ans = 0
        if n<0:
            n = n & 0xffffffff
        while n:
            ans += n & 1
            n >>= 1
        return ans
```
- 骚操作：
```python
# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1(self, n):
        # write code here
        ans = 0
        if n < 0:
            n = n & 0xffffffff
        while n:
            if n % 2 == 0:
                n /= 2
            else:
                n -= 1
                ans += 1
        return ans
```

## 数值的整数次方

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

- 思路：
    - 直接调库可行但不是最终目的
    - 分三种情况：
        - 大于0
        - 等于0
        - 小于0
- 常规：
```python
# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base, exponent):
        # write code here
        if base == 0:
            return False
        if exponent > 0:
            tmp = base
            for _ in range(exponent - 1):
                base *= tmp
            return base
        if exponent == 0:
            return 1
        if exponent < 0:
            tmp = base
            for _ in range(-exponent - 1):
                base *= tmp
            base = 1 / base
            return base
```
- 调库：
```python
# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base, exponent):
        # write code here
        return pow(base, exponent)
```

## 调整数组顺序使奇数位于偶数前面

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

- 分别建立奇偶数数组
```python
# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        # write code here
        odd_array = []  # 偶数
        even_array= []  # 奇数
        for item in array:
            if item % 2 == 0:
                odd_array.append(item)
            else:
                even_array.append(item)
        return even_array + odd_array
```
- 双指针：
```python
# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        # write code here
        if len(array) == 0 or len(array) == 1:
            return array
        length = len(array)  # list length
        even_point = odd_point = 0
        while odd_point < length:
            if array[odd_point] % 2 == 1:
                tmp = array[odd_point]
                for i in range(odd_point, even_point, -1):  # even number sorted array
                    array[i] = array[i - 1]
                array[even_point] = tmp  # even number reset
                odd_point += 1  # odd point move next
                even_point += 1  # even point move next
            else:
                odd_point += 1
        return array
```

## 链表中倒数第k个结点

输入一个链表，输出该链表中倒数第k个结点。

```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        point_1 = point_2 = head
        for _ in range(k):
            if point_2 is None:
                return None
            point_2 = point_2.next
        while point_2:
            point_2 = point_2.next
            point_1 = point_1.next
        return point_1
```

## 反转链表

输入一个链表，反转链表后，输出新链表的表头。

```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        head = None
        while pHead:
            tmp = ListNode(pHead.val)
            tmp.next = head
            head = tmp
            pHead = pHead.next
        return head
```

## 合并两个排序的链表

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        # write code here
        return_ = ListNode(None)
        tmp = return_
        p1, p2 = pHead1, pHead2
        while p1 and p2:
            if p1.val < p2.val:
                tmp.next = ListNode(p1.val)
                p1 = p1.next
            else:
                tmp.next = ListNode(p2.val)
                p2 = p2.next
            tmp = tmp.next
        if p1:
            tmp.next = p1
        if p2:
            tmp.next = p2
        return return_.next
```

## 树的子结构

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def HasSubtree(self, pRoot1, pRoot2):
        # write code here
        def subtree(pRoot1, pRoot2):
            if not pRoot1 and not pRoot2:
                return True
            if not pRoot1 or not pRoot2:
                return False
            if pRoot1.val == pRoot2.val:
                if pRoot2.left is None and pRoot2.right is None:
                    return True
                if subtree(pRoot1.left, pRoot2.left) and subtree(pRoot1.right, pRoot2.right):
                    return True
            return subtree(pRoot1.left, pRoot2) or subtree(pRoot1.right, pRoot2)
        
        if pRoot1 is None and pRoot2 is None:
            return False
        return subtree(pRoot1, pRoot2)
```
## 二叉树的镜像

操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
```
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
```

```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回镜像树的根节点
    def Mirror(self, root):
        # write code here
        if root is None:
            return
        self.Mirror(root.left)
        self.Mirror(root.right)
        root.left, root.right = root.right, root.left
```

## 顺时针打印矩阵

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
- 自己的：（有问题）
```python
# -*- coding:utf-8 -*-
class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        # write code here
        n = len(matrix)
        right, down, left, up = n - 1, n - 1, 0, 0
        i, j = 0, 0  # i是行，j是列
        sum_ = 1
        while sum_ <= n * n:
            # right
            for j in range(left, right + 1):
                matrix[i][j] = sum_
                sum_ += 1
            right -= 1
            # down
            for i in range(up + 1, down + 1):
                matrix[i][j] = sum_
                sum_ += 1
            down -= 1
            # left
            for j in range(right, left - 1, -1):
                matrix[i][j] = sum_
                sum_ += 1
            left += 1
            # up
            for i in range(down, up, -1):
                matrix[i][j] = sum_
                sum_ += 1
            up += 1
        for row in range(n):
            for col in range(n):
                print(matrix[n][n], ', ')
                if row == n and col == n:
                    print(matrix[n][n], '.')
```
- ：
```python
# -*- coding:utf-8 -*-
class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        # write code here
        m=len(matrix)
        ans=[]
        if m==0:
            return ans
        n=len(matrix[0])
        #ans = [[0 for i in range(n)] for j in range(n)]
        #print ans
        upper_i =0;lower_i=m-1;left_j=0;right_j=n-1
        num=1
        i=0;j=0
        right_pointer=1
        down_pointer=0
        while(num<=m*n):
            ans.append(matrix[i][j])
            if right_pointer==1:
                if j<right_j:
                    j=j+1
                else:
                    right_pointer=0
                    down_pointer=1
                    upper_i = upper_i+1
                    i = i+1
            elif down_pointer == 1:
                if i<lower_i:
                    i = i+1
                else:
                    right_pointer=-1
                    down_pointer=0
                    right_j = right_j -1
                    j = j-1
            elif right_pointer ==-1:
                if j > left_j:
                    j=j-1
                else:
                    right_pointer=0
                    down_pointer=-1
                    lower_i =lower_i-1
                    i = i-1
            elif down_pointer == -1:
                if i > upper_i:
                    i=i-1
                else:
                    right_pointer=1
                    down_pointer=0
                    left_j = left_j +1
                    j = j+1
            num=num+1
        return ans
```

## 包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

```python
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, node):
        # write code here
        self.stack.append(node)
        self.min_stack.append(node)
        self.min_stack.sort()

    def pop(self):
        # write code here
        pop_value = self.stack.pop()
        self.min_stack.remove(pop_value)
        self.min_stack.sort()

    def top(self):
        # write code here
        return self.stack[-1]

    def min(self):
        # write code here
        return self.min_stack[0]
```

## 栈的压入、弹出序列

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

```python
# -*- coding:utf-8 -*-
class Solution:
    def IsPopOrder(self, pushV, popV):
        # write code here
        stack = []
        while (popV):
            print(stack, pushV, popV)
            if pushV and pushV[0] == popV[0]:  # push 1, pop 1
                pushV.pop(0)
                popV.pop(0)
            elif stack and stack[-1] == popV[0]:  # push number>1, use tmp_stack
                stack.pop()
                popV.pop(0)
            elif pushV:  # if != : add_tmp_stack
                stack.append(pushV.pop(0))
            else:
                return False
        return True
```

## 从上往下打印二叉树

从上往下打印出二叉树的每个节点，同层节点从左至右打印。

```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    def PrintFromTopToBottom(self, root):
        # write code here
        if not root:
            return []
        result = []
        tmp = [root]
        while len(tmp):
            cur = tmp.pop(0)
            result.append(cur.val)
            if cur.left:
                tmp.append(cur.left)
            if cur.right:
                tmp.append(cur.right)
        return result
```

## 二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

```python
# -*- coding:utf-8 -*-
class Solution:
    def VerifySquenceOfBST(self, sequence):
        # write code here
        if len(sequence) == 0:
            return False
        root = sequence[-1]
        
        i = 0
        for node in sequence[:-1]:
            if node > root:
                break
            i += 1
        for node in sequence[i:-1]:
            if node < root:
                return False
        left = True
        if i > 1:
            left = self.VerifySquenceOfBST(sequence[:i])
        right = True
        if i < len(sequence) - 2 and left:
            right = self.VerifySquenceOfBST(sequence[i+1:-1])
        return left and right
```

## 二叉树中和为某一值的路径

输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)

```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        ret = []

        def dfs(root, sum_, tmp):
            if root:
                if root.left is None and root.right is None:
                    if root.val == sum_:
                        tmp.append(root.val)
                        ret.append(tmp[:])
                else:
                    tmp.append(root.val)
                    dfs(root.left, sum_ - root.val, tmp[:])
                    dfs(root.right, sum_ - root.val, tmp[:])

        dfs(root, expectNumber, [])
        return ret
```

## 复杂链表的复制

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

```python
class Solution:
    # 返回 RandomListNode
    def Clone(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """

        if head == None:
            return head
        node_dict = {}
        node_dict[head] = RandomListNode(head.label)
        tmp = head
        while(head):
            random = head.random
            nexthd = head.next
            if random !=None:
                if random not in node_dict:
                    node_dict[random] = RandomListNode(random.label)
                node_dict[head].random = node_dict[random]
            if nexthd !=None:
                if nexthd not in node_dict:
                    node_dict[nexthd] = RandomListNode(nexthd.label)
                node_dict[head].next = node_dict[nexthd]
            head = head.next
        return node_dict[tmp]
```

## 二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def Convert(self, pRootOfTree):
        # write code here
        if pRootOfTree is None:  # judge none
            return pRootOfTree
        if pRootOfTree.left is None and pRootOfTree.right is None:
            return pRootOfTree  # judge one node
        left = self.Convert(pRootOfTree.left)  # left
        p = left
        if left:
            while(p.right):
                p = p.right
            p.right = pRootOfTree
            pRootOfTree.left = p
        right = self.Convert(pRootOfTree.right)  # right
        if right:
            pRootOfTree.right = right
            right.left = pRootOfTree
        return left if left else pRootOfTree
```

## 字符串的排列

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

```python
# -*- coding:utf-8 -*-
class Solution:
    def Permutation(self, ss):
        def dfs(s):
            if len(s) == '':
                return []
            if len(s) == 1:
                return [s]
            if len(s) == 2:
                return list(set([s[0] + s[1], s[1] + s[0]]))
            ans = set([])
            left = s[0]
            right = dfs(s[1:])
            for word in right:
                for i in range(len(word) + 1):
                    ans.add(word[:i] + left + word[i:])
            return list(ans)
        
        if ss == '':
            return []
        return sorted(dfs(ss))
```

## 数组中出现次数超过一半的数字

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

- 暴力：
```python
# -*- coding:utf-8 -*-
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        dict_ = {}
        for item in numbers:
            if item in dict_:
                dict_[item] += 1
            else:
                dict_[item] = 1
        for key in dict_:
            if dict_[key] > len(numbers) / 2:
                return key
        return 0
```
- 摩尔投票法
```python
# -*- coding:utf-8 -*-
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        if not numbers:
            return 0
        tmp, times = None, 0
        for item in numbers:
            if times == 0:
                tmp, times = item, 1
            elif tmp == item:
                times += 1
            else:
                times -= 1
        return tmp if numbers.count(tmp) * 2 > len(numbers) else 0
```

## 最小的K个数

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

- 暴力：
```python
# -*- coding:utf-8 -*-
class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        if len(tinput) < k:
            return []
        tinput.sort()
        return tinput[:k]
```

## 连续子数组的最大和


HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

- 贪心
```python
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        if len(array) == 1:
            return array[0]
        p_2 = p_1 = array[0]
        for i in range(1, len(array)):
            p_1 = max(p_1 + array[i], array[i])
            p_2 = max(p_1, p_2)
        return p_2
```
- two for
```python
# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        if len(array) == 0:
            return 0
        if len(array) == 1:
            return array[0]
        max_ = array[0]
        for i in range(len(array)):
            for j in range(i, len(array)):
                print(i, j, sum(array[i:j + 1]))
                if sum(array[i:j + 1]) > max_:
                    max_ = sum(array[i:j + 1])
                    print(max_)
        return max_
```

## 整数中1出现的次数（从1到n整数中1出现的次数）

求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

```python
# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        # write code here
        if n <= 1:
            return n
        last, sum_, position = 0, 0, 1
        while (n):
            num = n % 10
            n /= 10
            sum_ += position * n
            if num > 1:
                sum_ += position
            elif num == 1:
                sum_ += last + 1
            last += num * position
            position *= 10
        return sum_
```

## 把数组排成最小的数


输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

```python
# -*- coding:utf-8 -*-
class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        if not numbers: return None
        numbers = list(map(str, numbers))
        numbers.sort(cmp=lambda x, y: cmp(x + y, y + x))
        return '0' if numbers[0] == '0' else ''.join(numbers)
```

## 丑数

把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

```python
# -*- coding:utf-8 -*-
class Solution:
    def GetUglyNumber_Solution(self, index):
        # write code here
        if index == 0:
            return 0
        if index == 1:
            return 1
        list_ = [1]
        two, three, five = 0, 0, 0
        for _ in range(index - 1):
            two_, three_, five_ = list_[two] * 2, list_[three] * 3, list_[five] * 5
            min_ = min(two_, three_, five_)
            list_.append(min_)
            two += (min_ == two_)
            three += (min_ == three_)
            five += (min_ == five_)
        return min_
```

## 第一个只出现一次的字符位置

在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
- 二次循环
```python
# -*- coding:utf-8 -*-
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        hash_ = {}
        for i, item in enumerate(s):
            if item not in hash_:
                hash_[item] = 1
            else:
                hash_[item] += 1
        for i, item in enumerate(s):
            if hash_[item] > 1:
                pass
            else:
                return i
        return -1
```
- hash加队列
```python
# -*- coding:utf-8 -*-
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        queue = []
        memories = dict()
        for idx, char in enumerate(s):
            if char not in memories:
                queue.append(idx)
                memories[char] = 0
            memories[char] += 1
            while (queue and memories[s[queue[0]]] > 1):
                queue.pop(0)
        return queue[0] if queue else -1
```

## 数组中的逆序对

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5
- 双循环
```python
# 通过率50%，超时引起的
# -*- coding:utf-8 -*-
class Solution:
    def InversePairs(self, data):
        # write code here
        num = 0
        for i in range(len(data)):
            for j in range(i, len(data)):
                if data[i] > data[j]:
                    num += 1
        return num % 1000000007
```
- 先将原序列排序，然后从排完序的数组中取出最小的，它在原数组中的位置表示有多少比它大的数在它前面，每取出一个在原数组中删除该元素，保证后面取出的元素在原数组中是最小的，这样其位置才能表示有多少比它大的数在它前面，即逆序对数。
```python
# 通过率50%，超时引起的
class Solution:
    def InversePairs(self, data):
        count = 0
        copy = []
        for i in data:
            copy.append(i)
        copy.sort()
        for i in range(len(copy)):
            count += data.index(copy[i])
            data.remove(copy[i])
        return count%1000000007
```
- 合并
```python
class Solution:
    def InversePairs(self, data):
        return self.sort(data[:], 0, len(data)-1, data[:]) % 1000000007

    def sort(self, temp, left, right, data):
        if right - left < 1:
            return 0
        if right - left == 1:
            if data[left] < data[right]:
                return 0
            else:
                temp[left], temp[right] = data[right], data[left]
                return 1
        mid = (left + right) // 2
        res = self.sort(data, left, mid, temp) + self.sort(data, mid+1, right, temp)
		# 合
        i = left
        j = mid + 1
        index = left

        while i <= mid and j <= right:
            if data[i] <= data[j]:
                temp[index] = data[i]
                i += 1
            else:
                temp[index] = data[j]
                res += mid - i + 1
                j += 1
            index += 1
        while i <= mid:
            temp[index] = data[i]
            i += 1
            index += 1
        while j <= right:
            temp[index] = data[j]
            j += 1
            index += 1
        return res
```
- cpp
```cpp
class Solution {
public:
    int InversePairs(vector<int> data) {
        
        vector<int> temp(data);
        return merge(data, temp, 0, data.size()-1);
    }
private:
    int MOD = 1000000007;
    int merge(vector<int> &data, vector<int> &temp, int start, int end)
    {
        if(start >= end)
            return 0;
        int mid = (start + end) >> 1;
        int ans = (merge(temp, data, start, mid) + merge(temp, data, mid+1, end)) % MOD;
        int i = start, j = mid+1, k = start;
        while (i <= mid && j <= end)
        {
            if (temp[i] <= temp[j])
                data[k++] = temp[i++];
            else
            {
                data[k++] = temp[j++];
                ans = (ans + mid - i + 1) % MOD;
            }
        }
        while (i <= mid)
            data[k++] = temp[i++];
        while (j <= end)
            data[k++] = temp[j++];
        return ans;
    }
};
```

## 两个链表的第一个公共节点

输入两个链表，找出它们的第一个公共结点。
- 设链表pHead1的长度为a,到公共结点的长度为l1；链表pHead2的长度为b,到公共结点的长度为l2，有a+l2 = b+l1
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def FindFirstCommonNode(self, pHead1, pHead2):
        # write code here
        if pHead1 is None or pHead2 is None:
            return None
        pa, pb = pHead1, pHead2
        while pa != pb:
            pa = pHead2 if pa is None else pa.next
            pb = pHead1 if pb is None else pb.next
        return pa
```

## 数字在排序数组中出现的次数

统计一个数字在排序数组中出现的次数。
- 傻瓜方法：
```python
# -*- coding:utf-8 -*-
class Solution:
    def GetNumberOfK(self, data, k):
        # write code here
        num = 0
        for item in data:
            if item == k:
                num += 1
        return num
```
- 原来是可以用hash做的，但是因为是排序数组，所以可以用二分查找
```python
# -*- coding:utf-8 -*-
class Solution:
    def GetNumberOfK(self, data, k):
        # write code here
        start = 0
        end = len(data)-1
        while(start<=end):
            mid = (start+end)/2
            if data[mid]==k:
                cnt = 0
                tmp = mid
                while(tmp>=0 and data[tmp]==k):
                    cnt+=1
                    tmp-=1
                tmp = mid+1
                while(tmp<len(data) and data[tmp]==k):
                    cnt+=1
                    tmp+=1
                return cnt
            elif data[mid]>k:
                end = mid-1
            else:
                start = mid+1
        return 0
```

## 二叉树的深度

输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def TreeDepth(self, pRoot):
        # write code here
        if pRoot is None:
            return 0
        if pRoot.left is None and pRoot.right is None:
            return 1
        return max(self.TreeDepth(pRoot.left), self.TreeDepth(pRoot.right))+1
```

## 平衡二叉树

输入一棵二叉树，判断该二叉树是否是平衡二叉树。
- BST的定义为$|height(lefttree)−height(righttree)|<=1$，原问题拆分为计算树高度和判断高度差
```python
class Solution:
    def Treeheight(self, pRoot):
        if pRoot is None:
            return 0
        if pRoot.left is None and pRoot.right is None:
            return 1
        lh = self.Treeheight(pRoot.left)
        rh = self.Treeheight(pRoot.right)
        return max(rh, lh) + 1

    def IsBalanced_Solution(self, pRoot):
        # write code here
        if pRoot is None:
            return True
        return abs(self.Treeheight(pRoot.left)-self.Treeheight(pRoot.right)) <= 1
```

## 数组中只出现一次的数字

一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
```python
# -*- coding:utf-8 -*-
class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        arr = []
        for item in array:
            if item in arr:
                arr.remove(item)
            else:
                arr.append(item)
        return arr
```
- Counter
```python
import collections
class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        targets = []
        dic = collections.Counter(array)
        for key,value in dic.items():
            if value < 2:
                targets.append(key)
        return targets
```

## 和为S的连续正数序列

题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
- $S\%奇数=0$或者$S\%偶数=偶数／2$就说明有这个连续序列，但是注意是正数序列，可能会出现越界情况
```python
class Solution:
    def FindContinuousSequence(self, tsum):
        # write code here
        k = 2
        ret = []
        for k in range(2, tsum):
            if k % 2 == 1 and tsum % k == 0:  # 奇数
                tmp = []
                mid = tsum / k
                if mid - k / 2 > 0:
                    for i in range(mid - k / 2, mid + k / 2 + 1):
                        tmp.append(i)
                    ret.append(tmp[:])
            elif k % 2 == 0 and (tsum % k) * 2 == k:  # 偶数
                mid = tsum / k
                tmp = []
                if mid - k / 2 + 1 > 0:
                    for i in range(mid - k / 2 + 1, mid + k / 2 + 1):
                        tmp.append(i)
                    ret.append(tmp[:])
        ret.sort()
        return ret
```

## 和为S的两个数字

输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。

```python
# -*- coding:utf-8 -*-
class Solution:
    def FindNumbersWithSum(self, array, tsum):
        # write code here
        if not array or not tsum:
            return []
        for i in range(len(array)):
            for j in range(i + 1, len(array)):
                if array[i] + array[j] == tsum:
                    if i == j:
                        break
                    else:
                        return array[i], array[j]
        return []
```

## 左旋转字符串

汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

```python
# -*- coding:utf-8 -*-
class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        return s[n:] + s[:n]
```

## 翻转单词顺序列

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

```python
# -*- coding:utf-8 -*-
class Solution:
    def ReverseSentence(self, s):
        # write code here
        list_ = s.split(" ")
        list_.reverse()
        return ' '.join(list_)
```

## 扑克牌顺子

LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
```python
class Solution:
    def IsContinuous(self, numbers):
        # write code here
        if not numbers:
            return 0
        numbers.sort()
        zeros = numbers.count(0)
        for i, v in enumerate(numbers[:-1]):
            if v != 0:
                if numbers[i + 1] == v:
                    return False
                zeros -= (numbers[i + 1] - numbers[i] - 1)
                if zeros < 0:
                    return False
        return True
```

## 孩子们的游戏（圆圈中最后剩下的数）

每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
```python
# -*- coding:utf-8 -*-
class Solution:
    def LastRemaining_Solution(self, n, m):
        # write code here
        if n < 1: return -1
        final, start = -1, 0
        cnt = [i for i in range(n)]
        while cnt:
            k = (start + m - 1) % n
            final = cnt.pop(k)
            n -= 1
            start = k
        return final
```

## 求1+2+3+...+n

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
```python
# -*- coding:utf-8 -*-
class Solution:
    def Sum_Solution(self, n):
        # write code here
        if n == 1: return 1
        return n + self.Sum_Solution(n-1)
```

## 不用加减乘除做加法

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
- 不计进位的和为 a^b，进位就是 a&b 
- a+b = a^b + (a&b)<<1;
```java
public class Solution {
    public int Add(int a,int b) {
        int unit = a ^ b;  
        int carry_bit = a & b;  
        while(carry_bit != 0) {  
            int temp_a = unit;  
            int temp_b = carry_bit << 1;  
            unit = temp_a ^ temp_b;  
            carry_bit = temp_a & temp_b;  
        }  
        return unit;  
    }
}
```

## 把字符串转换成整数
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
- 如果有正负号，需要在数字之前，出现其他字符或者字符串为空都非法返回0
```python
class Solution:
    def StrToInt(self, s):
        # write code here
        flag = True
        pos = 1
        ret = None
        if s == '':
            return 0
        for i in s:
            if i == '+' or i == '-':
                if flag:
                    pos = -1 if i == '-' else 1
                    flag = False
                else:
                    return 0
            elif i >= '0' and i <= '9':
                flag = False
                if ret is None:
                    ret = int(i)
                else:
                    ret = ret * 10 + int(i)
            else:
                return 0
        return pos * ret if ret else 0
```

## 数组中重复的数字

在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
- 先把输入的数组排序，再从头到尾扫描排序后的数组，如果相邻的两个元素相等，则存在重复数字。时间复杂度O(nlogn).
```python
# -*- coding:utf-8 -*-
class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        # write code here
        numbers = sorted(numbers)
        for i in range(1, len(numbers)):
            if numbers[i] == numbers[i - 1]:
                duplication[0] = numbers[i]
                return True
        return False
```
- hash.从头到尾扫描数组的每个元素，每扫描到一个元素，都可以用O(1)的时间来判断哈希表中是否已经存在该数字，如果存在，说明找到了重复元素，如果不存在，则将其加入到哈希表中。时间复杂度O(n)，空间复杂度O(n)。
```python
# -*- coding:utf-8 -*-
class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        # write code here
        hash_table = [None] * len(numbers)
        for i in range(len(numbers)):
            hash_value = numbers[i]
            if hash_table[hash_value]:
                duplication[0] = hash_value
                return True
            else:
                hash_table[hash_value] = hash_value
        return False
```
- 由于数组中元素都在0~n - 1的范围内，如果这个数组中没有重复元素，那么当数组排序后，数字i将会处于i的位置。从头到尾依次扫描数组中的元素，当扫描第i个元素时，如果这个元素是i，则继续扫描下一个元素，如果不是i，而是m，则将其与第m个元素比较，如果两者相等，则找到了重复的数字，如果不相等，则将二者交换位置，重复该过程，直到找到重复元素。时间复杂度O(n)，空间复杂度O(1).
```python
# -*- coding:utf-8 -*-
class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        # write code here
        for i in range(len(numbers)):
            while numbers[i] != i:
                if numbers[numbers[i]] == numbers[i]:
                    duplication[0] = numbers[i]
                    return True
                else:
                    numbers[numbers[i]], numbers[i] = numbers[i], numbers[numbers[i]]
        return False
```

## 构建乘积数组

给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
- 分为下三角和上三角DP计算B 
下三角B[i]=A[0]A[1]A[2]..A[i−1]=B[i−1]A[i−1]B[i]=A[0]A[1]A[2]..A[i−1]=B[i−1]A[i−1] 
上三角（从最后往前）tmp=A[−1]A[−2]A[−3]...
```python
class Solution:
    def multiply(self, A):
        # write code here
        size = len(A)
        B = [1]*size
        for i in range(1,size):
            B[i] = B[i-1]*A[i-1]
        tmp = 1
        for i in range(size-2,-1,-1):
            tmp = tmp*A[i+1]
            B[i] = B[i]*tmp
        return B
```

## 正则表达式匹配

请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
```python
# -*- coding:utf-8 -*-
class Solution:
    # s, pattern都是字符串
    def __init__(self):
        self.dic = {}
    def match(self, s, p):
        # write code here
        if (s,p) in self.dic:
            return self.dic[(s,p)]
        if p == '':
            return s==''
        if len(p)==1 or p[1]!='*':
            self.dic[(s[1:],p[1:])] = self.match(s[1:],p[1:])
            return len(s)>0 and (p[0]=='.' or p[0]==s[0]) and self.dic[(s[1:],p[1:])]
        while(len(s) and (p[0]=='.' or p[0]==s[0])):
            self.dic[(s,p[2:])] = self.match(s,p[2:])
            if self.match(s[:],p[2:]):
                return True
            s = s[1:]
        self.dic[(s,p[2:])] = self.match(s,p[2:])
        return self.dic[(s,p[2:])]
```

## 表示数值的字符串

请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
```python
# -*- coding:utf-8 -*-
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        INVALID = 0
        SPACE = 1
        SIGN = 2
        DIGIT = 3
        DOT = 4
        EXPONENT = 5
        transitionTable = [[-1,  0,  3,  1,  2, -1],    # 0 no input or just spaces 
                           [-1,  8, -1,  1,  4,  5],    # 1 input is digits 
                           [-1, -1, -1,  4, -1, -1],    # 2 no digits in front just Dot 
                           [-1, -1, -1,  1,  2, -1],    # 3 sign 
                           [-1,  8, -1,  4, -1,  5],    # 4 digits and dot in front 
                           [-1, -1,  6,  7, -1, -1],    # 5 input 'e' or 'E' 
                           [-1, -1, -1,  7, -1, -1],    # 6 after 'e' input sign 
                           [-1,  8, -1,  7, -1, -1],    # 7 after 'e' input digits 
                           [-1,  8, -1, -1, -1, -1]]    # 8 after valid input input space
        state = 0
        i = 0
        while i < len(s):
            inputtype = INVALID
            if s[i] == ' ':
                inputtype = SPACE
            elif s[i] == '-' or s[i] == '+':
                inputtype = SIGN
            elif s[i] in '0123456789':
                inputtype = DIGIT
            elif s[i] == '.':
                inputtype = DOT
            elif s[i] == 'e' or s[i] == 'E':
                inputtype = EXPONENT
            state = transitionTable[state][inputtype]
            if state == -1:
                return False
            else:
                i += 1
        return state == 1 or state == 4 or state == 7 or state == 8
```

## 字符串流中第一个不重复的字符

请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
```python
# -*- coding:utf-8 -*-
class Solution:
    # 返回对应char
    def __init__(self):
        self.memory = dict()
        self.queue = []

    def FirstAppearingOnce(self):
        # write code here
        while len(self.queue) and self.memory[self.queue[0]] > 1:
            self.queue.pop(0)

        return self.queue[0] if len(self.queue) else '#'

    def Insert(self, char):
        # write code here
        if char not in self.memory:
            self.memory[char] = 0
        self.memory[char] += 1
        if self.memory[char] == 1:
            self.queue.append(char)
```

## 链表中环的入口结点

给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

- 哈希表
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        set_ = set()
        while pHead:
            if pHead in set_:
                return pHead
            else:
                set_.add(pHead)
            pHead = pHead.next
        return None
```
- 快慢指针
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        fast, slow = pHead, pHead
        while fast is not None and fast.next is not None:
            fast, slow = fast.next.next, slow.next
            if fast == slow:
                break
        if fast is None or fast.next is None:
            return None
        fast = pHead
        while slow != fast:
            fast, slow = fast.next, slow.next
        return fast
```

## 删除链表中重复的结点

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteDuplication(self, pHead):
        # write code here
        point = pHead
        return_ = ListNode(-1)
        tmp = return_
        flag = False
        while point and point.next:
            if point.val == point.next.val:
                flag = True
                point.next = point.next.next
            else:
                if flag:
                    flag = False
                else:
                    tmp.next = ListNode(point.val)
                    tmp = tmp.next
                point = point.next
        if point and flag is False:
            tmp.next = ListNode(point.val)
        return return_.next
```

## 二叉树的下一节点

给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
- 中序遍历的顺序为LVR 
则有以下三种情况： 
a. 如果该结点存在右子结点，那么该结点的下一个结点是右子结点树上最左子结点 
b. 如果该结点不存在右子结点，且它是它父结点的左子结点，那么该结点的下一个结点是它的父结点 
c. 如果该结点既不存在右子结点，且也不是它父结点的左子结点，则需要一路向祖先结点搜索，直到找到一个结点，该结点是其父亲结点的左子结点。如果这样的结点存在，那么该结点的父亲结点就是我们要找的下一个结点。
```python
# -*- coding:utf-8 -*-
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None
class Solution:
    def GetNext(self, pNode):
        # write code here
        # left root right
        if pNode is None:
            return None
        if pNode.right:
            tmp = pNode.right
            while(tmp.left):
                tmp = tmp.left
            return tmp
        p = pNode.next
        while(p and p.right == pNode):
            pNode = p
            p = p.next
        return p
```

## 对称的二叉树

请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
```python
class Solution:
    def Symmetrical(self, Lnode, Rnode):
        if Lnode is None and Rnode is None:
            return True
        if Lnode and Rnode:
            return Lnode.val == Rnode.val and self.Symmetrical(
                Lnode.right, Rnode.left) and self.Symmetrical(
                    Lnode.left, Rnode.right)
        else:
            return False

    def isSymmetrical(self, pRoot):
        # write code here
        if pRoot is None:
            return True
        return self.Symmetrical(pRoot.left, pRoot.right)
```

## 按之字形顺序打印二叉树

请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def Print(self, pRoot):
        # write code here
        if pRoot is None:
            return []
        stack = [pRoot]
        step = 1
        ret = []
        while (stack):
            tmpstack = []
            tmp = []
            for node in stack:
                tmp += [node.val]
                if node.left:
                    tmpstack.append(node.left)
                if node.right:
                    tmpstack.append(node.right)
            if step % 2 == 0:
                tmp.reverse()
            ret.append(tmp)
            step += 1
            stack = tmpstack[:]
        return ret
```

## 把二叉树打印成多行

从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, pRoot):
        # write code here
        if pRoot is None:
            return []
        stack = [pRoot]
        ret = []

        while(stack):
            tmpstack = []
            tmp = []
            for node in stack:
                tmp.append(node.val)
                if node.left:
                    tmpstack.append(node.left)
                if node.right:
                    tmpstack.append(node.right)
            ret.append(tmp[:])
            stack = tmpstack[:]
        return ret
```

## 序列化二叉树

请实现两个函数，分别用来序列化和反序列化二叉树
```python
class Solution:
    def Serialize(self, root):
        # write code here
        def doit(node):
            if node:
                vals.append(str(node.val))
                doit(node.left)
                doit(node.right)
            else:
                vals.append('#')
        vals = []
        doit(root)
        return ' '.join(vals)

    def Deserialize(self, s):
        # write code here
        def doit():
            val = next(vals)
            if val == '#':
                return None
            node = TreeNode(int(val))
            node.left = doit()
            node.right = doit()
            return node
        vals = iter(s.split())
        return doit()
```

## 二叉搜索树的第k个节点

给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
```python
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回对应节点TreeNode
    def KthNode(self, pRoot, k):
        # write code here
        stack = []
        node = pRoot
        while node:
            stack.append(node)
            node = node.left
        cnt = 1
        while (stack and cnt <= k):
            node = stack.pop()
            right = node.right
            while right:
                stack.append(right)
                right = right.left
            cnt += 1
        if node and k == cnt - 1:
            return node
        return None
```

## 数据流中的中位数

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
```python
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.nums = []

    def Insert(self, num):
        self.nums.append(num)

    def GetMedian(self, fuck):
        self.nums.sort()
        if len(self.nums) % 2 == 1:
            return self.nums[(len(self.nums) - 1) / 2]
        else:
            return (self.nums[len(self.nums) / 2] +
                    self.nums[len(self.nums) / 2 - 1]) / 2.0
```

## 滑动窗口的最大值

给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

```python
# -*- coding:utf-8 -*-
class Solution:
    def maxInWindows(self, num, size):
        # write code here
        if size == 0 or num == 0:
            return []
        if size > len(num):
            return []
        if size == len(num):
            return [max(num)]
        list_ = []
        for i in range(len(num) - size + 1):
            tmp_list = num[i:i + size]
            list_.append(max(tmp_list))
        return list_
```

## 矩阵中的路径

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
- dfs加记忆化搜索
```python
# -*- coding:utf-8 -*-
class Solution:
    def hasPath(self, matrix, rows, cols, path):
        def dfs(memories, r, c, s):
            if s == '':
                return True
            dx = [-1, 1, 0, 0]
            dy = [0, 0, -1, 1]
            for k in range(4):
                x = dx[k] + r
                y = dy[k] + c
                if x >= 0 and x < rows and y >= 0 and y < cols and memories[x][y] and matrix[x
                                                                                             *
                                                                                             cols
                                                                                             +
                                                                                             y] == s[0]:
                    memories[x][y] = False
                    if dfs(memories[:], x, y, s[1:]):
                        return True
                    memories[x][y] = True
            return False

        if path == '':
            return True
        memories = [[True for c in range(cols)] for r in range(rows)]
        for r in range(rows):
            for c in range(cols):
                if matrix[r * cols + c] == path[0]:
                    memories[r][c] = False
                    if dfs(memories[:], r, c, path[1:]):
                        return True
                    memories[r][c] = True
        return False
```

## 机器人的运动范围

地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
- dfs+记忆化搜索
```python
# -*- coding:utf-8 -*-
class Solution:
    def movingCount(self, threshold, rows, cols):
        # write code here
        memories = set()
        def dfs(i,j):
            def judge(i,j):
                return sum(map(int, list(str(i)))) + sum(map(int, list(str(j)))) <= threshold
            if not judge(i,j) or (i,j) in memories:
                return
            memories.add((i,j))
            if i != rows - 1:
                dfs(i + 1, j)
            if j != cols - 1:
                dfs(i, j + 1)
        dfs(0,0)
        return len(memories)
```
