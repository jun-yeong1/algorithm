#include <bits/stdc++.h>
#define MAX 16
#define INF 1e9;
using namespace std;

int n, dist[MAX][MAX];
int cache[MAX][1<<MAX];

int minCost(int here, int visited) {
    // ��� ���� �� ��� ���� ��ġ��
    if (visited == (1<<n)-1) {
        if (dist[here][0] == 0) {
            return INF;
            }
        else return dist[here][0];
    }
    int& ret = cache[here][visited];
    if (ret != -1) return ret;
    ret = INF;
    for (int next = 0; next < n; next++) {
        // �̹� �湮�� ���ô� �Ѿ / 0�� ��쵵 �Ѿ
        if (visited & (1<<next) || dist[here][next] == 0) continue;
        ret = min(ret, dist[here][next] + minCost(next, visited | (1<<next)));
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    fill(&cache[0][0], &cache[MAX-1][1<<MAX], -1);
    // 0�� ��� ���۽� 0�� ��� �湮 ó��
    cout << minCost(0, 1<<0);
}