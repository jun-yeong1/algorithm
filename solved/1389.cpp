#include <bits/stdc++.h>

using namespace std;

int n, m;
bool visited[101];
vector<int> graph[101];
int minp;

void bfs(int p) {
  queue<int> q;
  q.push(p);
  visited[p] = true;
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    minp += graph[x].size();
    for (int i = 0; i < graph[x].size(); i++) {
      int y = graph[x][i];
      if (!visited[y]) {
        q.push(y);
        visited[y] = true;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  getchar();

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    getchar();
  }
  for (int i = 0; i < n; i++) {
    bfs()
  }
  bfs(1);
}