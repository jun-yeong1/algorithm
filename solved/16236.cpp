#include <bits/stdc++.h>

using namespace std;

int n, shark = 2, result = 0; // 맵 크기, 상어 크기, 시간
int graph[20][20]; // 맵 저장
int visited[20][20];
int sx, sy; // 상어 위치
// x, y 위치
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = true;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    // 먹이를 먹은 후 상어 위치 저장
    if (graph[x][y] > 0 && graph[x][y] < shark) {
      if ((sy > y) || (sy == y && bx > x)) {
        bx = x;
        by = y;
        continue;
      }
    }
    q.pop();
    
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (graph[nx][ny] > 0 && graph[nx][ny] < shark) {
        graph[nx][ny] = 0;
        shark += 1;
        q.push({nx, ny});
      }
    }
  }
}

int main() {
  cin >> n;
  getchar();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%1d", &graph[i][j]); // 맵 저장
      if (graph[i][j] == 9) { //상어 처음 위치 저장
        sx = i, sy = j;
        graph[i][j] = 0; //상어 처음 위치를 0으로
      }
    }
    getchar();
  }
  bfs(sx, sy);
  cout << sx << sy;
}