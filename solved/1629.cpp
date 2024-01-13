#include <bits/stdc++.h>

using namespace std;

int a, b, c;

long long mult(long long x) {
    x = x % c;
    x = x * x;
    return x % c;
}
long long return_n(int n) {
    if (n == 1) return a;
    if (n % 2 > 0) return return_n(n - 1) * a;
    return mult(return_n(n / 2));
}

int main(void) {
    cin >> a >> b >> c;
    cout << return_n(b) % c;
}