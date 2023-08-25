#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    int result = 0;
    cin >> n >> m;
    int card[n];
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = (i + 1); j < n; j++) {
            for (int k = (j + 1); k < n; k++) {
                if ((card[i] + card[j] + card[k]) < m) {
                    result = max(result , (card[i] + card[j] + card[k]));
                }
                else if((card[i] + card[j] + card[k]) == m) {
                    result = card[i] + card[j] + card[k];
                    break;
                }
            }
        }
    }
    cout << result;
}