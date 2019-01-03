/*
    游戏任务标记
*/

#include <iostream>
using namespace std;

int main() {
    unsigned int id_1, id_2;
    while (cin >> id_1 >> id_2) {
        if (id_1 < 1 || id_1 > 1024 || id_2 < 1 || id_2 > 1024) {
            cout << -1 << endl;
        } else {
            if (id_1 == id_2)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}
