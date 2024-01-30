#include <bits/stdc++.h>

using namespace std;

int n;
int work[20][20];
int cache[20][1 << 20];
// p = 사람 수, visited = 한 일
int minCost(int p, int visited) {
    if (visited == (1 << n) - 1) return 0;
    int& ret = cache[p][visited];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int i = 0; i < n; i++) {
        // i번째가 포함되었는지 확인
        if (visited & (1 << i)) continue;
        // i를 visited에 포함시켜 재귀 
        ret = min(ret, minCost(p+1, visited | (1 << i)) + work[p][i]);
    }
    return ret;
}
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> work[i][j];
        }
    }
    //memset(&cache, -1, sizeof(cache));
    // 1 << 20 의 사이즈 따로 지정 20이 아님
    fill(&cache[0][0], &cache[19][1 << 20], -1);
    cout << minCost(0, 0);
}