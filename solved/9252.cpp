#include <bits/stdc++.h>

using namespace std;

string a, b;
int LCS[1001][1001];
char choices[1001];

void lcs_a() {
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i-1] == b[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
                choices[i] = a[i-1];
            } else {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    } 
}

int main(void) {
    cin >> a >> b;
    lcs_a();
    int result = LCS[a.size()][b.size()];
    cout << result << '\n';
    // 문자 구하기
    int i = a.size();
    int j = b.size();
    int n = result;
    while (i != 0 && j != 0) {
        if (LCS[i-1][j] == n) {
            i -= 1;
        } else if (LCS[i][j-1] == n) {
            j -= 1;
        } else {
            choices[n] = a[i-1];
            i -= 1;
            j -= 1;
            n -= 1;
        }
    }
    for (int i = 1; i <= result; i++) {
        cout << choices[i];
    }
}