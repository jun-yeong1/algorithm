#include <iostream>
#include <string>

using namespace std;
int n, m;
char graph[50][50]; 
bool visited[50][50];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dfs(int x, int y, int px, int py, int num) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (graph[nx][ny] != graph[x][y]) continue;
        if (nx == px && ny == py) continue;
        if (visited[nx][ny] && num >= 4) {
            return true;
        }
        if (!visited[nx][ny]) {
            if (dfs(nx, ny, x, y, num + 1)) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < m; j++) {
            graph[i][j] = a[j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (dfs(i, j, -1, -1, 1)) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }

    cout << "No";
    return 0;
}