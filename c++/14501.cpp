#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> work;
int pay[15];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        work.push_back({a, b});
    }
    memset(pay, 0, sizeof(pay));
    if (work[n-1].first == 1) {
        pay[n-1] = work[n-1].second;
    }
    for (int i = n-2; i >= 0; i--) {
        if (work[i].first + i <= n) {
            pay[i] = max(pay[i+1], work[i].second + pay[i + work[i].first]);
        } else {
            pay[i] = pay[i+1];
        }
    }
    cout << pay[0] << endl;
}