#include <bits/stdc++.h>

using namespace std;
int n, m, sum;
int memory[100], c[100];
int cache[10000];

void cost() {
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= c[i]; j--) {
            cache[j] = max(cache[j], cache[j - c[i]] + memory[i]);
        }
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> memory[i];
    }
    
    for (int j = 0; j < n; j++) {
        cin >> c[j];
        sum += c[j];
    }
    cost();
    for (int i = 0; i <= sum; i++) {
        if (cache[i] >= m) {
            cout << i;
            break;
        }
    }
}