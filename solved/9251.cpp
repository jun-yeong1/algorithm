#include <bits/stdc++.h>

using namespace std;

string a, b;
int LCS[1001][1001];
void lcs_a() {
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i-1] == b[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            } else {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
}
int main(void) {
    cin >> a >> b;
    lcs_a();
    cout << LCS[a.size()][b.size()];
}