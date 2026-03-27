#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    // 내림차순 priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }
    int result = 0;
    while(!q.empty()) {
        int num = 0;
        num = q.top();
        q.pop();
        if (q.empty()) {
            break;
        }
        num += q.top();
        q.pop();
        result += num;
        if (q.empty()) {
            break;
        } else {
            q.push(num);
        }
    }
    cout << result << endl;

    return 0;
}