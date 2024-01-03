#include<bits/stdc++.h>
#define INF 1e9

using namespace std;

// 노드 수 n, 간선 수 m, 시작 노드
int n, m, start; 
// 노드 정보 동적 배열
vector<pair<int, int> > graph[20001];
// 최단거리 테이블
int d[20001];

// 다익스트라 알고리즘
void dijkstra(int start) {
  priority_queue<pair<int, int> > pq;
  pq.push({0, start});
  d[start] = 0;

  while (!pq.empty()) {
    int dist = -pq.top().first; // 최대 힙으로 되어있어 부호 -
    int now = pq.top().second;
    pq.pop();
    if (d[now] < dist) continue;
    for (int i = 0; i < graph[now].size(); i++) {
      int cost = dist + graph[now][i].second;
      if (cost < d[graph[now][i].first]) {
        d[graph[now][i].first] = cost;
        // 최대 힙이라 부호 반대
        pq.push(make_pair(-cost, graph[now][i].first)); 
      }
    }
  }
}

int main(void) {
  cin >> n >> m;
  cin >> start;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }
  fill_n(d, 20001, INF);
  dijkstra(start);

  for (int i = 1; i <= n; i++) {
    if(d[i] == INF) {
      cout << "INF" << '\n';
    }
    else {
      cout << d[i] << '\n';
    }
  }
}