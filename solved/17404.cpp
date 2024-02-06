#include <bits/stdc++.h>

using namespace std;

int n;
int cost[1000][3], cache[1000][3];
int result;
// 현재 집, 그전 집 색
void color() {
    result = 1e9;
    for (int RGB = 0; RGB < 3; RGB++) {
        for (int i = 0; i < 3; i++) {
            if (i == RGB) {
                cache[0][i] = cost[0][i];
            } else {
                cache[0][i] = 1e9;
            }
        }
        for (int i = 1; i < n; i++) {
            cache[i][0] = cost[i][0] + min(cache[i-1][1], cache[i-1][2]);
            cache[i][1] = cost[i][1] + min(cache[i-1][0], cache[i-1][2]);
            cache[i][2] = cost[i][2] + min(cache[i-1][0], cache[i-1][1]);
        }
        for (int i = 0; i < 3; i++) {
            if (i == RGB) continue;
            else result = min(result, cache[n-1][i]);
        }
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    memset(cache, 0, sizeof(cache));
    color();
    cout << result;
}