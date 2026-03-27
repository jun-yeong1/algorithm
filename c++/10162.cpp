#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int a = 300;
    int b = 60;
    int c = 10;
    int a_cnt = 0, b_cnt = 0, c_cnt = 0;
    if (t / a > 0) {
        a_cnt = t / a;
        t = t % a;
    }
    if (t / b > 0) {
        b_cnt = t / b;
        t = t % b;
    }
    if (t / c > 0) {
        c_cnt = t / c;
        t = t % c;
    }
    if (t != 0) {
        cout << -1 << endl;
    } else {
        cout << a_cnt << " " << b_cnt << " " << c_cnt << endl;
    }

    return 0;
}