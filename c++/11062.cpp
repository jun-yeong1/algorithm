#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];
int arr[MAX];

int card(int x, int y, bool turn) {
    if (dp[x][y] != -1) return dp[x][y]; // 동적계획
    if (x > y) return 0;
    if (turn) {
        dp[x][y] = max(card(x+1, y, !turn) + arr[x], card(x, y-1, !turn) + arr[y]);
    } else {
        dp[x][y] = min(card(x+1, y, !turn), card(x, y-1, !turn));
    }
    return dp[x][y];
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(dp, -1, sizeof(dp));
        int n; // 카드 수
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        cout << card(0, n-1, true) << endl;
    }
    return 0;
}