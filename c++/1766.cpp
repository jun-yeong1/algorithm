#include <iostream>
#include <vector>
#include <queue>

#define MAX 32001

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int in[MAX] = {0,};
    vector<int> graph[MAX];
    vector<int> result;
    // 우선순위 큐 작은 값부터
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // int &k : graph[a]
        ///for (int k = 0; k < graph[b].size(); k++)
        graph[a].push_back(b);
        in[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int front = q.top();
        result.push_back(front);
        q.pop();
        for (int i : graph[front]) {
            in[i]--;
            if (in[i] == 0) {
                q.push(i);
            }
        }
    }

    for(int i : result) {
        printf("%d ", i);
    }

    return 0;
}