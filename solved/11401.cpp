#include <bits/stdc++.h>
#define DIV 1000000007
using namespace std;

int n, k;
long long f_nk;
// ÆÑÅä¸®¾ó
long long fac(long long x) {
    if (x == 1 || x == 0) return 1;
    return (fac(x - 1) % DIV) * x % DIV ;
}
// Á¦°ö
long long mult(long long m) {
    m %= DIV;
    return m * m % DIV;
}
// ºÐÇÒ Á¤º¹
long long prime(long long p) {
    if (p == 1) return f_nk;
    if (p % 2 > 0) return prime(p - 1) * f_nk % DIV;
    return mult(prime(p / 2)) % DIV;
}

int main(void) {
    cin >> n >> k;
    f_nk = fac(n-k) * fac(k) % DIV;
    long long fib_n = fac(n) % DIV;
    cout << (fib_n * prime(DIV-2) % DIV);
}