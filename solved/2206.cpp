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

int bfs(int x, int y) {
    queue<qu> q;
    visited[0][0][0] = 1;
    q.push({0, 0, 0});
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int wall = q.front().wall;
        q.pop();
        if (x == n-1 && y == m-1) return visited[x][y][wall];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nwall = wall;
            // 공간을 넘어갔을 때
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 방문했던 장소 넘어감
            if (visited[nx][ny][wall]) continue;
            // 벽 있음, 벽 부순적 없음, 방문 안함
            if (graph[nx][ny] == 1 && nwall == 0) {
                visited[nx][ny][1] = visited[x][y][wall] + 1;
                nwall = 1;
                q.push({nx, ny, nwall});
            }
            // 벽 없음, 방문 안함
            if (graph[nx][ny] == 0) {
                visited[nx][ny][nwall] = visited[x][y][wall] + 1;
                q.push({nx, ny, wall});
            }
        }
    }
    return -1;
}
int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
    cout << bfs(0, 0);
    return 0;
}