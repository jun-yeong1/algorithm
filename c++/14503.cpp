#include <iostream>
#include <queue>

using namespace std;

int arr[50][50];
int result = 0;
int four[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// [x+1][y] = 남, [x][y+1] = 동
// [x-1][y] = 북, [x][y-1] = 서
bool check(int x, int y) {
    if (arr[x+1][y] != 0 && arr[x-1][y] != 0
        && arr[x][y+1] != 0 && arr[x][y-1] != 0) {
        return false;
    } else {
        return true;
    }
}

void robo(int x, int y, int view) {
    // 조건 1
    if (arr[x][y] == 0) {
        result++;
        arr[x][y] = -1;
    }
    // 조건 2
    if(!check(x, y)) {
        int back = view;
        back = (back + 6) % 4;
        if (arr[x+four[back][0]][y+four[back][1]] != 1) {
            robo(x+four[back][0], y+four[back][1], view);
        }
    } else { // 조건 3
        int current = view;
        for (int i = 0; i < 4; i++) {
            current = (current + 3) % 4; // 90도 이동
            if (arr[x+four[current][0]][y+four[current][1]] == 0) {
                robo(x+four[current][0], y+four[current][1], current);
                break;
            } else {
                continue;
            }
        }
    }
}


int main() {
    int N, M;
    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d; // d가 0 = 북쪽, 1 = 동쪽, 2 = 남쪽, 3 = 서쪽
    //   0
    // 3   1
    //   2
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    robo(r, c, d);
    cout << result;

    return 0;
}