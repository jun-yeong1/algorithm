#include <bits/stdc++.h>

using namespace std;
int n, k;
// ¹«°Ô
vector<pair<long, long> > ja;
vector<long> bag;

long long thief() {
    priority_queue<int> pq;
    int index = 0;
    long long result = 0;
    for (int i = 0; i < k; i++) {
        while(index < n && bag[i] >= ja[index].first) {
            pq.push({ja[index].second});
            index++;
        }
        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }
    return result;
}

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        long m, v;
        cin >> m >> v;
        ja.push_back({m, v});
    }
    for (int i = 0; i < k; i++) {
        long b;
        cin >> b;
        bag.push_back({b}); 
    }
    sort(ja.begin(), ja.end());
    sort(bag.begin(), bag.end());
    cout << thief();
}