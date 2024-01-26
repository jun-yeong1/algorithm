#include <bits/stdc++.h>
#define MAX_C 1000000000
using namespace std;

int n;
long city[100000];
long road[100000];
long long cost;

void mini() {
    long mincity = MAX_C;
    for (int i = 0; i < n-1; i++) {
        mincity = min(mincity, city[i]);
        cost += mincity * road[i];
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> road[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> city[i];
    }
    mini();
    cout << cost;
}