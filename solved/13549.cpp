#include <bits/stdc++.h>
#define INF 100010

using namespace std;

int N, K;

vector<int> dist(100001, INF);

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        if (here + 1 <= 100000) {
            if (cost + 1 < dist[here + 1]) {
                dist[here + 1] = cost + 1;
                pq.push({-(cost+1), (here + 1)});   
            }
        }
        if (here - 1 >= 0) {
            if (cost + 1 < dist[here - 1]) {
                dist[here - 1] = cost + 1;
                pq.push({-(cost+1), (here - 1)});
            }
        }
        if (here * 2 <= 100000) {
            if (cost < dist[here * 2]) {
                dist[here * 2] = cost;
                pq.push({-cost, (here * 2)});
            }
        }
    }
}
int main(void) {
    cin >> N >> K;
    if (N >= K) {
        cout << N - K;
        return 0;
    } else {
        dijkstra(N);
        cout << dist[K];
        return 0;
    }
}
