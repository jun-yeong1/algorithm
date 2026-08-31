#include <iostream>
#include <algorithm>
using namespace std;

int arr[21][21];
int n, m;

int price(int k) {
    return k*k + (k+1) * (k+1);
}

int gold_cnt(int row, int col, int k) {
    int gold_num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(abs(row - i) + abs(col - j) <= k) {
                gold_num += arr[i][j];
            }
        }
    }
    return gold_num;
}
int main() {
    int result = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            for(int k = 0; k <= 2 * (n-1); k++) {
                int num_of_gold = gold_cnt(row, col, k);

                // 손해를 보지 않으면서 채굴할 수 있는 최대 금의 개수를 저장합니다.
                if(num_of_gold * m >= price(k)) {
                    result = max(result, num_of_gold);
                }
            }
        }
    }

    cout << result << endl;
    return 0;
}