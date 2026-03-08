#include <iostream>
#include <vector>

using namespace std;

int n;
int pastNode;
int maxDist = 0;
bool visited[10001];
vector<pair<int, int>> graph[10001];

void dfs(int start, int dist) {
    visited[start] = true;
    if (dist > maxDist) {
        maxDist = dist;
        pastNode = start;
    }
    for (auto next : graph[start]) {
        if (!visited[next.first]) {
            dfs(next.first, dist + next.second);
        }
    }
}

int main () {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y, num;
        cin >> x >> y >> num;
        graph[x].push_back({y, num});
        graph[y].push_back({x, num});
    }
    dfs(1, 0);
    fill(visited, visited+10001, false);
    dfs(pastNode, 0);
    cout << maxDist << endl;
    return 0;
}