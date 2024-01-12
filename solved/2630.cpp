#include <bits/stdc++.h>
#define MAX_N 128
using namespace std;

int paper[MAX_N][MAX_N];
// 색종이 개수
int white, blue = 0;

void tree(int y, int x, int size) {
    int color = paper[y][x];
    for (int dy = y; dy < y + size; dy++) {
        for (int dx = x; dx < x + size; dx++) {
            if (paper[dy][dx] != color) {
                int half = size / 2;
                tree(y, x, half);
                tree(y, x + half, half);
                tree(y + half, x, half);
                tree(y + half, x + half, half);
                return;
            }
        }
    }
    if (color == 0) {
        white += 1;
    } else blue += 1;
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    tree(0, 0, n);
    cout << white << '\n' << blue;
}