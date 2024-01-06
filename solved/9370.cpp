#include <bits/stdc++.h>
#define INF 50000000
using namespace std;

//���� ��
int n;

vector<pair<int, int> > graph[2001];

vector<int> dijkstra(int start) {
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    // ����ġ, ���� ����
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i].first;
            int nextDist = cost + graph[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
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
        for (int i = 1; i <= n; i++) {
            //vector<pair<int, int> >().swap(graph[i]);
            graph[i].clear();
        }
        // s = �����, g-h = ������ ����
        int s, g, h;
        cin >> s >> g >> h;
        int dist_gh; 
        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
            if ((a == g && b == h) || (a == h && b == g)) {
                dist_gh = d;
            }
        }
        // ������ �ĺ� ���� ����
        vector<int> end_t;
        for (int j = 0; j < t; j++) {
            int temp;
            cin >> temp;
            end_t.push_back(temp);
        }
        sort(end_t.begin(), end_t.end());
        // ���ͽ�Ʈ�� �� ���� ��� ����
        vector<int> f_dist(n+1, INF);
        vector<int> s_dist(n+1, INF);
        f_dist = dijkstra(s);
        // ����� + g or h + g-h �Ÿ�
        int dist_sum;
        if (f_dist[g] <= f_dist[h]) {
            s_dist = dijkstra(h);
            dist_sum = f_dist[g] + dist_gh;
        } else {
            s_dist = dijkstra(g);
            dist_sum = f_dist[h] + dist_gh;
        }
        for (int k = 0; k < end_t.size(); k++) {
            int node_t = end_t[k];
            int dist_t = f_dist[node_t];
            if (dist_t != INF) {
                long long total = dist_sum + s_dist[node_t];
                if (total != INF &&  dist_t == total) {
                    cout << node_t << " ";
                } else continue;
            }
        }
        cout << endl;
    }
}