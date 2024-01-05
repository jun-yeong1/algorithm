#include <bits/stdc++.h>
#define INF 50000001
using namespace std;
// ���� ��
int n;

vector<pair<int, int> > graph[2001];

vector<int> dijkstra(int start) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    // ����ġ, ���� ����
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
    // �׽�Ʈ ���̽� ��
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        // n = ����, m = ����, t = �������ĺ� ��
        int m, t;
        cin >> n >> m >> t;
        // s = �����, g-h = ������ ����
        int s, g, h;
        cin >> s >> g >> h;
        // ������ �ĺ� ���� ����
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
        // ���ͽ�Ʈ�� �� �� ��� ����
        vector<int> f_dist(n, INF);
        vector<int> s_dist(n, INF);
        // ����� + g or h + g-h �Ÿ�
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