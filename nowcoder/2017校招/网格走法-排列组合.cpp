/*
    网格走法数目
*/

#include <iostream>
using namespace std;

int step(int m, int n) {
    if (n == 0 || m == 0)
        return 1;
    return step(m, n - 1) + step(m - 1, n);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << step(x, y) << endl;
    return 0;
}

/*
    排列组合
    做左上角走到右下角，需要x次向右，y次像左走
*/
