#include <bits/stdc++.h>
#define INF 50000001
using namespace std;
// 정점 수
int n;

vector<pair<int, int> > graph[2001];

vector<int> dijkstra(int start) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    // 가중치, 정점 순서
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i].first;
            int nextDist = cost + graph[here][i].second;
            if (dist[here] > nextDist) {
                dist[here] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dist;
}

int main (void) {
    // 테스트 케이스 수
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        // n = 정점, m = 간선, t = 목적지후보 수
        int m, t;
        cin >> n >> m >> t;
        // s = 출발지, g-h = 지나간 간선
        int s, g, h;
        cin >> s >> g >> h;
        // 목적지 후보 저장 벡터
        vector<int> end_t(t);
        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }
        for (int j = 0; j < t; j++) {
            int t;
            cin >> t;
            end_t.push_back(t);
        }
        sort(end_t.begin(), end_t.end());
        // 다익스트라 두 번 결과 저장
        vector<int> f_dist(n, INF);
        vector<int> s_dist(n, INF);
        // 출발지 + g or h + g-h 거리
        int dist_sum;
        f_dist = dijkstra(s);
        if (f_dist[g] <= f_dist[h]) {
            s_dist = dijkstra(g);
            dist_sum = f_dist[g] + s_dist[h];
        } else {
            s_dist = dijkstra(h);
            dist_sum = f_dist[h] + s_dist[g];
        }
        for (int k = 0; k < end_t.size(); k++) {
            if (f_dist[end_t[k]] == dist_sum + s_dist[end_t[k]]) {
                cout << end_t[k] << " ";
            } else continue;
        }
        cout << endl;
    }
}