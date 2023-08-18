#include <bits/stdc++.h>

using namespace std;

int n, min_s = 2;
int graph[n][n];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) {

}

int main() {
  cin >> n;
  getchar();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%1d", &graph[i][j]);
    }
  }
}