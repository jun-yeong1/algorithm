#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001];
int dist[100001]; 
int parent[100001];
int N, K;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == K) return;
        for (int next : {x + 1, x - 1, x * 2}) {
            if (next >= 0 && next <= 100000) {
                if (!visited[next]) {
                    visited[next] = true;
                    parent[next] = x;
                    dist[next] = dist[x] + 1;
                    q.push(next);
                }
            }
        }
    } 
}

int main() {
    cin >> N >> K;

    bfs(N);

    cout << dist[K] << endl;

    vector<int> path;
    for (int i = K; i != N; i = parent[i]) {
        path.push_back(i);
    }
    path.push_back(N);
    reverse(path.begin(), path.end());

    for (int x : path) {
        cout << x << " ";
    }

    return 0;
}