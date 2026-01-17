#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 501

int main() {
    int test;
    cin >> test;

    for (int k = 0; k < test; k++) {
        int n, m;
        int ti[MAX] = {0,}; // 옛날 순위
        int graph[MAX][MAX]; // 현재 그래프
        int in[MAX] = {0,}; // 진입 차수 계산
        vector<int> result; // 결과 저장
        queue<int> q;
        fill_n(graph[0], MAX*MAX, 0);

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> ti[i];
        }
        for (int i = 0; i < n; i++) {
            if (i == n-1) break;
            for (int j = i+1; j < n; j++) {
                graph[ti[i]][ti[j]] = 1;
                in[ti[j]]++;
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (graph[b][a] != 0) {
                graph[b][a] = 0;
                graph[a][b] = 1;
                in[a]--;
                in[b]++;
            } else {
                graph[b][a] = 1;
                graph[a][b] = 0;
                in[a]++;
                in[b]--;
            }
        }
        for (int i = 1; i < n+1; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        int taggle = 0;
        for (int i = 0; i < n; i++) {
            if(q.empty()) {
                taggle = 1;
                break;
            }
            int front = q.front();
            result.push_back(front);
            q.pop();
            for (int i = 1; i < n+1; i++) {
                if (graph[front][i] == 1) {
                    in[i]--;
                    if(in[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        if (taggle != 0) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for (int x : result) {
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}