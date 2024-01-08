#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

// n 도시 수, m 버스 수
int n, m;
// 버스 비용 테이블
int graph[101][101];

int main(void) {
    cin >> n;
    cin >> m;
    // graph 값 INF로 초기화
    for (int i = 0; i < 101; i++) {
        fill(graph[i], graph[i] + 101, INF);
    }
    // 자기 자신 비용 0 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) graph[i][j] = 0;
        }
    }
    // a = 시작도시 b = 도착도시 c = 비용
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (graph[a][b] > c) {
            graph[a][b] = c;
        } else continue;
    }
    // 플로이드 워셜 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    // 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == INF) {
                cout << "0" << " ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << '\n';
    }
}