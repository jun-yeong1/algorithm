#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int> > AB;
int right_e[101];
int cache[101];

int lis(int start) {
    int& ret = cache[start];
    if (ret != -1) return ret;
    ret = 1;
    for (int next = start+1; next < n; next++) {
        if (right_e[start] < right_e[next]) {
            ret = max(ret, lis(next) + 1);
        }
    }
    return ret;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        AB.push_back({a, b});
    }
    sort(AB.begin(), AB.end());
    for (int i = 0; i < n; i++) {
        right_e[i] = AB[i].second;
    }
    fill_n(cache, 101, -1);
    for (int i = 0; i < n; i++) {
        lis(i);
    }
    int max_lis = 0;
    for (int i = 0; i < n; i++) {
        max_lis = max(max_lis, cache[i]);
    }
    cout << n - max_lis;
}