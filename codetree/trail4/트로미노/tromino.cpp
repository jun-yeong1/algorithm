#include <iostream>
#include <algorithm>
using namespace std;

int arr[201][201];

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    int max_n = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    // 네 칸씩보고 최대값
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            // 네 칸 중에서 작은거 하나를 뺀 것 = 가장 큰 경우
            int f_num = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
            int max_f = f_num - min({arr[i][j], arr[i][j+1], arr[i+1][j], arr[i+1][j+1]});
            max_n = max(max_n, max_f);
        }
    }

    // 가로, 세로 나눠서 보기
    // 가로
    for (int i = 0; i < n; i++) {
        int row = 0;
        for (int j = 0; j < m-2; j++) {
            max_n = max(max_n, arr[i][j] + arr[i][j+1] + arr[i][j+2]);
        }
    }
    // 세로
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m; j++) {
            max_n = max(max_n, arr[i][j] + arr[i+1][j] + arr[i+2][j]);
        }
    }

    cout << max_n << endl;

    return 0;
}