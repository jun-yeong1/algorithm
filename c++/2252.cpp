#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define MAX 32001

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> graph[MAX];
    int in[MAX] = {0,}; // 진입 차수 계산
    // fill_n(in, MAX, 0);
    vector<int> result;
    queue<int> q;   

    for (int i = 0; i < m; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B); // 순방향 A -> B
        in[B] += 1; // 진입 차수 +1
    }
    
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int front = q.front();
        result.push_back(front);
        q.pop();
        for (int i : graph[front]) {
            in[i] -= 1;
            if (in[i] == 0) {
                q.push(i);
            }
        }
    }

    for (int x : result) {
        printf("%d ", x);
    }

    return 0;
}