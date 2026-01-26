#include <iostream>
#include <queue>
#include <vector>

#define MAX 501
using namespace std;

int n, m;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> result;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    int size = 0;
    visited[x][y] = true;
    q.push({x, y});
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        size++;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (!visited[nx][ny] && graph[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    result.push_back(size);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && graph[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    int max = 0;
    for (int i : result) {
        if (max < i) {
            max = i;
        }
    }
    cout << result.size() << endl;
    if (result.size() == 0) {
        cout << 0 << endl;
    } else {
        cout << max << endl;
    }
}