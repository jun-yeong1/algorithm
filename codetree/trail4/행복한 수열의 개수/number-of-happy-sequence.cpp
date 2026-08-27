#include <iostream>
using namespace std;

int arr[101][101];
int main() {
    int n, m;
    int result = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    // m 개씩 같은 열과 행이 있는지 확인
    int row = 0;
    int col = 0;
    for (int i = 0; i < n; i++) {
        int row_n = 1;
        int col_n = 1;
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                row = arr[i][0];
                row_n = 1;
            } else if (row != arr[i][j]) {
                row = arr[i][j];
                row_n = 1;
            } else {
                row_n++;
            }
            if (row_n >= m) {
                result++;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                col = arr[0][i];
                col_n = 1;
            } else if (col != arr[j][i]) {
                col = arr[j][i];
                col_n = 1;
            } else {
                col_n++;
            }
            if (col_n >= m) {
                result++;
                break;
            }
        }
    }
    cout << result << endl;

    return 0;
}