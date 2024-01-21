#include <bits/stdc++.h>

using namespace std;
int n, m;
int map_n[500][500], cache[500][500];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int road(int x, int y) {
    int& ret = cache[x][y];
    if (x == m-1 && y == n-1) return 1;
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (map_n[nx][ny] < map_n[x][y]) {
                ret += road(nx, ny);
            }
        }
    }
    return ret;
}
int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map_n[i][j];
        }
    }
    fill(&cache[0][0], &cache[499][500], -1);
    cout << road(0, 0);
}