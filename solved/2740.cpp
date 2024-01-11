#include <bits/stdc++.h>

using namespace std;
int n, m, k;

int graphA[100][100], graphB[100][100], graph[100][100];

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graphA[i][j];
        }
    }
    cin >> m >> k;;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> graphB[i][j];
        }
    }
    for (int p = 0; p < n; p++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                graph[p][i] += graphA[p][j] * graphB[j][i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
}