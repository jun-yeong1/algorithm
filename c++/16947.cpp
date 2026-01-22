#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;
vector<int> graph[3001];
bool visited[3001];
bool bfs_visited[3001];
bool cycle[3001];
int result[3001];
bool hasCycle;
int pre[3001];

void bfs () {
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        // 사이클 안이라면 거리 0
        if (cycle[i]) {
            bfs_visited[i] = true;
            q.push({i, 0});
        }
    }

    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        bfs_visited[cur] = true;

        for (int i : graph[cur]) {
            if (bfs_visited[i]) continue;
            result[i] = dist + 1;
            q.push({i, dist + 1});
        }
    }
}

void findCycle (int x) {
    visited[x] = true;
    for(int i : graph[x]) {
        if (hasCycle) return;
        if (visited[i]) {
            if (i != pre[x]) {
                cycle[x] = true;
                hasCycle = true;
                // 사이클에 있는 노드를 true로 변경
                while (x != i) {
                    cycle[pre[x]] = true;
                    x = pre[x];
                }
                return;
            }
        } else {
            pre[i] = x; // 각 노드의 부모 노드 저장
            findCycle(i);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    findCycle(1);
    bfs();
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}