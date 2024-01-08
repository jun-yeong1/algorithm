#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

// n ���� ��, m ���� ��
int n, m;
// ���� ��� ���̺�
int graph[101][101];

int main(void) {
    cin >> n;
    cin >> m;
    // graph �� INF�� �ʱ�ȭ
    for (int i = 0; i < 101; i++) {
        fill(graph[i], graph[i] + 101, INF);
    }
    // �ڱ� �ڽ� ��� 0 �ʱ�ȭ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) graph[i][j] = 0;
        }
    }
    // a = ���۵��� b = �������� c = ���
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (graph[a][b] > c) {
            graph[a][b] = c;
        } else continue;
    }
    // �÷��̵� ���� �˰���
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    // ���
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