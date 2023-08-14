#include <bits/stdc++.h>

using namespace std;

int com = 0, nek = 0, result = 0;
bool visited[101];
vector<int> graph[101];

void dfs(int x) {
  visited[x] = true;
  for (int i = 0; i < graph[x].size(); i++) {
    int y = graph[x][i];
    if (!visited[y]) {
      dfs(y);
      result++;
    }
  }
}

int main(){
  cin >> com;
  cin >> nek;
  
  for (int i = 0; i < nek; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 0; i < com; i++) {
		visited[i] = false;
	}
  dfs(1);

  cout << result << '\n';
}

