#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
// N = 도시 수, M = 버스 노선 수 
int N, M;

vector<pair<int, int> > graph[501];

vector<long long> bellman(int start) {
    vector<long long> upper(N+1, INF);
    upper[start] = 0;
    bool updated;
    // N번 순회
    for(int iter = 1; iter <= N; iter++) {
        updated = false;
        for (int here = 1; here <= N; here++) {
            for (int i = 0; i < graph[here].size(); i++) {
                int there = graph[here][i].first;
                int cost = graph[here][i].second;
                //완화
                if (upper[here] != INF && upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
    }
    // N번 째에도 완화가 된다면 음수 사이클 존재
    if (updated) upper[0] = -1;
    return upper;
}

int main(void) {
    cin >> N >> M;
    // 버스 노선 정보
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
    }
    vector<long long> result;
    result = bellman(1);
    if (result[0] == -1) {
        cout << -1;
    } else {
        for (int i = 2; i <= N; i++) {
            if (result[i] < INF - 100) {
                cout << result[i];
            } else {
                cout << -1;
            }
            cout << '\n';
        }
    }
}