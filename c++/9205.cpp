#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

// 최대 거리 50m = 1 bottle, 1000m = 20 bottle
#define MAX 1000
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int home_x, home_y;
        cin >> home_x >> home_y;
        vector<pair<int, int>> store(n);
        for (int j = 0; j < n; j++) {
            cin >> store[j].first >> store[j].second;
        }
        int rock_x, rock_y;
        cin >> rock_x >> rock_y;
        // bfs
        queue<pair<int, int>> q;
        q.push({home_x, home_y});

        bool visited[101] = {false};
        bool happy = false;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int end = abs(cur.first - rock_x) + abs(cur.second - rock_y);
            if (end <= MAX) {
                happy = true;
                break;
            }
            for (int k = 0; k < n; k++) {
                if (visited[k]) continue;
                int dist = abs(cur.first - store[k].first) + abs(cur.second - store[k].second);
                if (dist <= MAX) {
                    visited[k] = true;
                    q.push(store[k]);
                }
            }
        }
        if (happy) cout << "happy" << endl;
        else cout << "sad" << endl;
    }
}