#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> graph[101];
auto bfs(int v) {
  bool visited[101] = {false, };
  visited[v] = true;
  int count = 0;
  int sum = 0;
  queue<int> q;
  q.push(v);
  while(!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      int node = q.front();
      q.pop();
      sum += count;
      for (int i = 0; i < graph[node].size(); i++) {
        int x = graph[node][i];
        if(!visited[x]) {
          visited[x] = true;
          q.push(x);
        }
      }
    }
    count++;
  }
  return sum;
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
  int min_sum = 999999;
  int result = 0;
  for (int i = 1; i < (n+1); i++) {
    int bfs_sum = bfs(i);
    if (bfs_sum < min_sum) {
      min_sum = bfs_sum;
      result = i;
    }
  }
  cout << result;
}