#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    // one:연속된 0 개수, zero:연속된 1 개수
    int one = 0, zero = 0; // cnt:연속된 수 종류
    char cnt = s[0];
    for (int i = 1; i < size(s); i++) {
        // 숫자 변경될 시
        if (cnt != s[i]) {
            if (cnt == '1') {
                one++;
                cnt = '0';
            } else {
                zero++;
                cnt = '1';
            }
        }
        if (i == size(s)-1) {
            if (cnt == '1') {
                one++;
            } else {
                zero++;
            }
        }
    }
    if ((one == 1 && zero == 0) || (one == 0 && zero == 1)) {
        cout << 0 << endl;
    } else if (one >= zero) {
        cout << zero << endl;
    } else {
        cout << one << endl;
    }
    return 0;
}