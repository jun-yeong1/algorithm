#include <iostream>
#include <algorithm>
using namespace std;

int arr[20][20];
int n;

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int cicle(int x, int y, int k, int l) {
    int num = 0;
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {1, -1, -1, 1};
    int move[4] = {k, l, k, l};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < move[i]; j++) {
            x += dx[i];
            y += dy[i];
            if (!ok(x, y)) {
                return 0;
            }
            num += arr[x][y];
        }
    }

    return num;
}

int main() {
    int max_num = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 1; k < n; k++)
                for(int l = 1; l < n; l++)
                    max_num = max(max_num, cicle(i, j, k, l));

    cout << max_num << "\n";
    return 0;
}