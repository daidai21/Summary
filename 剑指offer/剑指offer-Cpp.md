### 二维数组中的查找

```cpp
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for (int row = 0; row < array.size(); row++) {
            for (int col = 0; col < array[0].size(); col++) {
                if (target == array[row][col]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

### 替换空格

```cpp

```
