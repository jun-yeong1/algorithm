#include <bits/stdc++.h>

using namespace std;

int white[101][101] = {{0, }, };

int main() {
    int paper = 0;
    cin >> paper;
    for (int i = 0; i < paper; i++) {
        int x, y;
        cin >> x >> y;
        // 색종이 덮은 부분 처리
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                white[x + j][y + k] = 1;
            }
        }
    }
    int result = 0;
    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            if (white[i][j] == 1) {
                result++;
            }
        }
    }
    cout << result;
}