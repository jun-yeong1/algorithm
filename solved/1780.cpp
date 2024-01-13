#include <bits/stdc++.h>
#define MAX_N 2187

using namespace std;

int paper[MAX_N][MAX_N];
// m_0 = -1, zero = 0, p_0 = +1
int m_o, zero, p_o = 0;

void tree(int y, int x, int size) {
    int num = paper[y][x];
    for (int dy = y; dy < y + size; dy++) {
        for (int dx = x; dx < x + size; dx++) {
            if (paper[dy][dx] != num) {
                int th = size / 3;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tree(y + (th * i), x + (th * j), th);
                    }
                }
                return;
            }
        }
    }
    if (num == -1) {
        m_o += 1;
    } else if (num == 0) {
        zero += 1;
    } else p_o += 1;
}

int main(void) {
    int N;
    cin >> N;
    for (int  i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    tree(0, 0, N);
    cout << m_o << '\n' << zero << '\n' << p_o;
}
