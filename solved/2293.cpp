#include <bits/stdc++.h>

using namespace std;
int n, k;
int coin[100], sum[10001];

int coin_n() {
    sum[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            sum[j] = sum[j] + sum[j - coin[i]];
        }
    }
    return sum[k];
}

int main(void) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    cout << coin_n();
}