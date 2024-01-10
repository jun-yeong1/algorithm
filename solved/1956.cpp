#include <bits/stdc++.h>
#define INF 4000001
using namespace std;

int V, E;

int graph[401][401];

void cycle() {
    for (int k = 0; k < V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
int main(void) {
    cin >> V >> E;
    for (int i = 0; i < 401; i++) {
        fill(graph[i], graph[i]+401, INF);
    }
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // make_pair 두번째 값에 따라 내림차 정렬
        // 같으면 첫번째 값에 따라 오름차 정렬
        graph[a][b] = c;
    }
    cycle();
    int result = INF;
    for (int i = 1; i <= V; i++) {
        if (graph[i][i] != INF) {
            result = min(result, graph[i][i]);
        }
    }
    if (result != INF) {
        cout << result;
    } else cout << -1;
}