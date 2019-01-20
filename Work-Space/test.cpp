#include <iostream>
#include <vector>

using namespace std;

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
