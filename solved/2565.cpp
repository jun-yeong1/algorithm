#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int, int> > AB;
int cache[101];
int elc(int start) {
    int& ret = cache[start];
    if (ret != -1) return ret;
    ret = 0;
    for (int next = start+1; next < n; next++) {
        if ((AB[start].first < AB[next].first && AB[start].second > AB[next].second) 
        || (AB[start].first > AB[next].first && AB[start].second < AB[next].second)) {
            ret = elc(next) + 1;
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
    fill_n(cache, 101, -1);
    for (int i = 0; i < n; i++) {
        elc(i);
    }
    for (int i = 0; i < n; i++) {
        cout << cache[i] << " ";
    }
}