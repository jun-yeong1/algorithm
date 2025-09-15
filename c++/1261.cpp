#include <iostream>
#include <string>
#include <queue>
#define MAX 1000000;
using namespace std;

int N, M;
int arr[101][101];
int visited[101][101];
int four[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs() {
    queue<pair<int, int> > q;
    q.push({0, 0});
    visited[0][0] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + four[i][0];
            int ny = y + four[i][1];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(arr[nx][ny] == 1) {
                if (visited[nx][ny] > visited[x][y] + 1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            } else if (arr[nx][ny] == 0) {
                if (visited[nx][ny] > visited[x][y]) {
                    visited[nx][ny] = visited[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }

}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        string num;
        cin >> num;
        for (int j = 0; j < N; j++) {
            arr[i][j] = num[j];
            arr[i][j] -= '0';
            visited[i][j] = MAX;
        }
    }
    bfs();
    cout << visited[M - 1][N - 1];

    return 0;
}