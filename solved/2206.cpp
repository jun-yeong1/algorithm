#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
// 구조체
typedef struct {
    int x;
    int y;
    int wall;
}qu;

int n, m;
int graph[1000][1000];
// 0, 1로 벽 부순 것 표현
int visited[1000][1000][2];
// 상하좌우 움직임 좌표
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y) {
    queue<qu> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int wall = q.front().wall;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 공간을 넘어갔을 때
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 벽 있음, 벽 부순적 없음, 방문 안함
            if (graph[nx][ny] == 1 && wall == 0 && !visited[nx][ny][wall+1]) {
                visited[nx][ny][wall + 1] = true;
                result[nx][ny] = result[x][y] + 1;
                q.push({nx, ny, wall+1});
            }
            // 벽 없음, 방문 안함
            if (graph[nx][ny] == 0 && !visited[nx][ny][wall]) {
                result[nx][ny] = result[x][y] + 1;
                q.push({nx, ny, wall});
            }
        }
    }
}
int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
    bfs(0, 0);
    if (result[n - 1][m - 1] == 0) {
        cout << -1;
    } else {
        cout << result[n - 1][m - 1] + 1;
    }
    return 0;
}