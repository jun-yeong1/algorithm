#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>> max_pq; // 최대힙 아래것
    priority_queue<int, vector<int>, greater<int> > min_pq; // 최소힙 위 것

    for (int i = 0; i < N; i++) {
        int num = 0;
        scanf("%d", &num);
        if ((i % 2) == 0) {
            max_pq.push(num);
        } else {
            min_pq.push(num);
        }
        if (!min_pq.empty() && !max_pq.empty()) {
            if(min_pq.top() < max_pq.top()) {
                int min = min_pq.top();
                int max = max_pq.top();
                min_pq.pop();
                max_pq.pop();
                min_pq.push(max);
                max_pq.push(min);
            }
        }
        printf("%d\n", max_pq.top());
    }
    return 0;
}