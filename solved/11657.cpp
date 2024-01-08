#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
// N = ���� ��, M = ���� �뼱 �� 
int N, M;

vector<pair<int, int> > graph[501];
// reachable[u][v] = u->v ��� ����
bool reachable[501][501] = {false};

vector<int> bellman(int start) {
    vector<int> upper(N+1, INF);
    upper[start] = 0;
    // N-1�� ��ȸ
    for(int iter = 0; iter < N-1; iter++) {
        for (int here = 0; here < N; here++) {
            for (int i = 0; i < graph[here].size(); i++) {
                int there = graph[here][i].first;
                int cost = graph[here][i].second;
                upper[there] = min(upper[there], upper[here] + cost);
            }
        }
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (reachable[i][j] || (reachable[i][k] && reachable[k][j]))
                reachable[i][j] = true;
            }
        }
    }
    // N�� ��ȸ (��������Ŭ ������ �� N��° ��ȭ ����)
    for (int here = 0; here < N; here++) {
        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i].first;
            int cost = graph[here][i].second;
            if (upper[here] + cost < upper[there]) {
                if (reachable[start][here+1]) {
                    upper[0] = -1;
                    cout << "w";
                }
            }
        }
    }
    return upper;
}

int main(void) {
    cin >> N >> M;
    // ���� �뼱 ����
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back(make_pair(B, C));
        reachable[A][B] = true;
    }
    vector<int> result;
    result = bellman(1);
    //cout << result[0];
    if (result[0] == -1) {
        cout << -1;
    } else {
        for (int i = 2; i <= N; i++) {
            if (result[i] != INF) {
                cout << result[i] << '\n';
            } else {
                cout << "-1" << '\n';
            }
        }
    }
}