#include <iostream>
#include <queue>
#define MAX 1000000001

using namespace std;

long long a, b;

int bfs(int start) {
    queue<pair<long long, int>> q;
    q.push({start, 0});
    while(!q.empty()) {
        long long x = q.front().first;
        int count = q.front().second;
        q.pop();
        if(x == b) {
            cout << count + 1 << endl;
            return 0;
        }
        long long fis = x * 2;
        long long sec = (x * 10) + 1;
        if (fis < MAX) {
            q.push({fis, count+1});
        }
        if (sec < MAX) {
            q.push({sec, count+1});
        }
    }
    cout << -1 << endl;
    return 0;
}

int main() {
    cin >> a >> b;
    bfs(a);

    return 0;
}