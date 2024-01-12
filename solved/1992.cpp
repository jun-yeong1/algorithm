#include <bits/stdc++.h>
#define MAX_N 64
using namespace std;

string graph[MAX_N];

void tree(int y, int x, int size) {
    char color = graph[y][x];
    for (int dy = y; dy < y + size; dy++) {
        for (int dx = x; dx < x + size; dx++) {
            if (graph[dy][dx] != color) {
                cout << "(";
                int half = size / 2;
                tree(y, x, half);
                tree(y, x + half, half);
                tree(y + half, x, half);
                tree(y + half, x + half, half);
                cout << ")";
                return;
            }
        }
    }
    cout << color;
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }
    tree(0, 0, n);
}