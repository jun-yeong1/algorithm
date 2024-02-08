#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int, int> > line;

long long solve() {
    long long start = line[0].first;
    long long end = line[0].second;
    long long result = 0;
    for (int i = 1; i < n; i++) {
        // 연결되지 않은 선분
        if (line[i].first > end) {
            result += end - start;
            start = line[i].first;
            end = line[i].second;
        } else if (line[i].first <= end && line[i].second > end) {
            end = line[i].second;
        } else if (line[i].second <= end) continue;
    }
    result += end - start;
    return result;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        line.push_back(make_pair(a, b));
    }
    sort(line.begin(), line.end());
    cout << solve();
}