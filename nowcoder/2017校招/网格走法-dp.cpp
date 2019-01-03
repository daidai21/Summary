/*
    网格走法数目
*/

#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int array[x + 1][y + 1];
    for (int i = 0; i <= x; i++){
        array[i][0] = 1;
    }
    for (int j = 0; j <= y; j++) {
        array[0][j] = 1;
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            array[i][j] = array[i - 1][j] + array[i][j - 1];
        }
    }
    cout << array[x][y] << endl;
    return 0;
}

/*
    dp

动态规划：
对于x*Y网格，dp[i][j]表示到达(i,j)位置一共有多少种走法,
因为每次只能向下或是向右走，所以第一列和第一行到达所有位置
的走法都是1，即dp[i][0]=1,dp[0][j]=1(0=<i<=x,0<=j<=y)，
对于其他位置，走法应该等于其左边格点的走法和其上面格点的走法之和，
*/
