#include <bits/stdc++.h>

using namespace std;

int R, C;
char graph[20][20];
bool alp[26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int result = 1;

void dfs(int x, int y, int n) {
  result = max(result, n);
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
    if (!alp[graph[nx][ny] - 'A']) {
      alp[graph[nx][ny] - 'A'] = true;
      dfs(nx, ny, n + 1);
      alp[graph[nx][ny] - 'A'] = false;
    }
  }
  
}

int main() {
  cin >> R >> C;
  getchar();
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      // 공백없이 입력받은 것을 배열에 넣기
      scanf("%1c", &graph[i][j]); 
    }
    getchar();
  }
  alp[graph[0][0] - 'A'] = true;
  dfs(0, 0, 1);
  
  cout << result << '\n';
}