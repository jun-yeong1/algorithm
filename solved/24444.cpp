#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > adj(100001);
vector<int> order;
int num;

void bfs(int start) {
    vector<bool> discovered(adj.size(), false);
    queue<int> q;
    discovered[start] = true;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        order[here] = num;
        num += 1;
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i];
            if (!discovered[there]) {
                q.push(there);
                discovered[there] = true;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    order = vector<int>(n+1, 0);
    num = 1;
    bfs(r);
    for (int i = 1; i <= n; i++) {
        cout << order[i] << '\n';
    }
}