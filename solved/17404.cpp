#include <bits/stdc++.h>

using namespace std;

int n;
int cost[1000][3], cache[1000][1<<3];

// 현재 집, 그전 집 색
int color(int start, int colored) {
    int& ret = cache[start][colored];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int i = 0; i < n; i++) {
        if ()
        if (colored & (1<<1)) {
            ret = min(ret, color(i, colored | (1<<2)) + cost[i][1]);
            ret = min(ret, color(i, colored | (1<<3)) + cost[i][2]);
        } else if (colored & (1<<2)) {
            ret = min(ret, color(i, colored | (1<<1)) + cost[i][0]);
            ret = min(ret, color(i, colored | (1<<3)) + cost[i][2]);
        } else if (colored & (1<<3)) {
            ret = min(ret, color(i, colored | (1<<1)) + cost[i][0]);
            ret = min(ret, color(i, colored | (1<<2)) + cost[i][1]);
        }
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    memset(cache, -1, sizeof(cache));
}