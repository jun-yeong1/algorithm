#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 牢立青纺
vector<vector<int> > adj(100000);
// 规巩咯何
vector<bool> visited;
vector<int> result;
int num;
void dfs(int here) {
    result[here] = num;
    num += 1;
    visited[here] = true;
    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if (!visited[there]) {
            dfs(there);
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
    visited = vector<bool>(n, false);
    result = vector<int>(n+1, 0);
    num = 1;
    dfs(r);
    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }
}