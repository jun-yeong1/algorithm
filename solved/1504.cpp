#include <bits/stdc++.h>
#define INF 1e8

using namespace std;

int N, E, v1, v2;
vector<pair<int, int> > graph[801];

int dijkstra(int start, int end) {
  vector<int> dist(N + 1, INF);
  dist[start] = 0;
  priority_queue<pair<int, int> > pq;
  pq.push({0, start});
  while(!pq.empty()) {
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    if(dist[here] < cost) continue;
    for (int i = 0; i < graph[here].size(); i++) {
      int there = graph[here][i].first;
      int nextDist = cost + graph[here][i].second;
      if (dist[there] > nextDist) {
        dist[there] = nextDist;
        pq.push(make_pair(-nextDist, there));
      }
    }
  }
  return dist[end];
}

int main(void) {
  cin >> N >> E;
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  cin >> v1 >> v2;

  int startV1 = dijkstra(1, v1);
  int startV2 = dijkstra(1, v2);

  int secondV1 = dijkstra(v1, v2);
  int endV1 = dijkstra(v1, N);

  int secondV2 = dijkstra(v2, v1);
  int endV2 = dijkstra(v2, N);
  
  long long result1, result2;
  result1 = startV1 + secondV1 + endV2;
  result2 = startV2 + secondV2 + endV1;
  
  long long result = min(result1, result2);

  if (result >= INF) {
    cout << "-1";
  } else {
    cout << result;
  }
}