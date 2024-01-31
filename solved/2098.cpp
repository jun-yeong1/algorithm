#include <bits/stdc++.h>
#define MAX 16
using namespace std;

int n, dist[MAX][MAX];
double cache[MAX][1<<MAX];

double minCost(int here, int visited) {
    // 모든 도시 돌 경우 시작 위치로
    if (visited == (1<<n)-1) return dist[here][0];
    double& ret = cache[here][visited];
    if (ret >= 0) return ret;
    ret = 1e6;
    for (int next = 0; next < n; next++) {
        // 이미 방문한 도시는 넘어감
        if (visited & (1<<next)) continue;
        double cand =  dist[here][next] + minCost(next, visited + (1<<next));
        ret = min(ret, cand);
    }
    return ret;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    fill(&cache[0][0], &cache[MAX-1][1<<MAX], -1);
    cout << minCost(0, 0);
}