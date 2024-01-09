#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
// N = ���� ��, M = ���� �뼱 �� 
int N, M;

vector<pair<int, int> > graph[501];

vector<long long> bellman(int start) {
    vector<long long> upper(N+1, INF);
    upper[start] = 0;
    bool updated;
    // N�� ��ȸ
    for(int iter = 1; iter <= N; iter++) {
        updated = false;
        for (int here = 1; here <= N; here++) {
            for (int i = 0; i < graph[here].size(); i++) {
                int there = graph[here][i].first;
                int cost = graph[here][i].second;
                //��ȭ
                if (upper[here] != INF && upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
    }
    // N�� °���� ��ȭ�� �ȴٸ� ���� ����Ŭ ����
    if (updated) upper[0] = -1;
    return upper;
}

int main(void) {
    cin >> N >> M;
    // ���� �뼱 ����
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