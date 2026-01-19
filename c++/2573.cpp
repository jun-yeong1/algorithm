#include <iostream>
#include <cstring>

#define MAX 300
using namespace std;

int n, m;
int graph[MAX][MAX];
bool visited[MAX][MAX];
// 동서남북
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// 얼음이 두 개인지 확인
void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (!visited[nx][ny] && graph[nx][ny] != 0) {
            dfs(nx, ny);
        }
    }
}
// 녹은 얼음 처리
void bfs() {
    int temp[MAX][MAX] = {0,};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] != 0) {
                int sea = 0; // 바다수
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (graph[nx][ny] == 0) sea++;
                }
                // 0 or 남은 얼음 층수
                temp[i][j] = max(0, graph[i][j] - sea);
            }
        }
    }
    // 얼음 녹은 temp로 graph 덮어쓰기
    memcpy(graph, temp, sizeof(graph));
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    int year = 0;
    while(true) {
        memset(visited, false, sizeof(visited));

        int count = 0; // 얼음 수
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] != 0 && !visited[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }
        if (count >= 2) {
            cout << year << endl;
            return 0;
        }
        if (count == 0) {
            cout << 0 << endl;
            return 0;
        }
        bfs();
        year++;
    }
}