/*
    幸运数
*/

#include <iostream>

using namespace std;

int f(int n) { // 各位数字之和
    int add = 0;
    while (n >= 10) {
        int x;
        x = n % 10;
        n = (n - x) / 10;
        add += x;
    }
    add += n;
    return add;
}

int g(int n) { // 二进制数之和
    int add = 0;
    while (n >= 2) {
        int x;
        x = n % 2;
        n = (n - x) / 2;
        add += x;
    }
    add += n;
    return add;
}

int main() {
    int n;
    cin >> n;
    int sum = 0; // 幸运数的数量
    for (int i = 1; i <= n; i++) {
        if (f(i) == g(i)) 
            sum++;
    }
    cout << sum << endl;
    return 0;
}
