#include <iostream>
#include <queue>

using namespace std;
int t;
int main() {
    cin >> t;

    while (t--) {
        // 우선순위 큐 작은 것부터
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long result = 0;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int a;
            cin >> a;
            pq.push(a);
        }
        while (pq.size() != 1) {
            long long a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(a+b);
            result = result + a+b;
        }
        cout << result << endl;
    }
    return 0;
} 