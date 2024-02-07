#include <bits/stdc++.h>
#define MOD 1000000003

using namespace std;

int n, k;
long long cache[1001][500];

// start = 색깔 수, num = 선택할 수
long long mun(int start, int num) {
    // 해당 경우 반복을 끝낸다.
    if (start != 0 && num == 1) return start;
    else if ((start / 2) < num) return 0;
    long long& ret = cache[start][num];
    if (ret != -1) return ret;
    ret = 0;
    // mun(n, k) = mun(n-1, k) + mun(n-2, k-1)
    ret = (mun(start-1, num) % MOD) + (mun(start-2, num-1) % MOD);
    return ret;
}

int main(void) {
    cin >> n;
    cin >> k;
    memset(cache, -1, sizeof(cache));
    cout << mun(n, k) % MOD;
}