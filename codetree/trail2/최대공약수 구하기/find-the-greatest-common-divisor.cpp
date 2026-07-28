#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a = 0;
    if (n <= m) {
        a = n;
    } else {
        a = m;
    }
    for (int i = a; i > 0; i--) {
        int tag = 0;
        if (n % i == 0) {
            if (m % i == 0) {
                tag = 1;
                cout << i << endl;
            }
        }
        if (tag == 1) {
            break;
        }
    }
    return 0;
}