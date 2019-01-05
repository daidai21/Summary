/*
    解救小易
*/

#include <iostream>
#include <vector>
using namespace std;

int array[1001][1001];
int min_trap_time = 2000; // 最短落入陷阱时间

int main(){
    int n;
    cin >> n;
    vector<int> x, y;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        x.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        y.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        if (x[i] + y[i] < min_trap_time)
            min_trap_time = x[i] + y[i];
    }
    cout << min_trap_time - 2 << endl;
    return 0;
}
