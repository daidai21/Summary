/*
    身份证数组
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        if (str.length() <= 6) { // 1
            cout << str << endl;
        } else if (str.length() <= 14) { // 2
            string str_1, str_2;
            for (int i = 0; i < 6; i++) {
                str_1 += str[i];
            }
            for (int i = 6; i < str.length(); i++) {
                str_2 += str[i];
            }
            cout << str_1 << " " << str_2 << endl;
        } else { // 3
            string str_1, str_2, str_3;
            for (int i = 0; i < 6; i++) {
                str_1 += str[i];
            }
            for (int i = 6; i < 14; i++) {
                str_2 += str[i];
            }
            for (int i = 14; i < str.length(); i++) {
                str_3 += str[i];
            }
            cout << str_1 << " " << str_2 << " " << str_3 << endl;
        }
    }
    return 0;
}
