#include <iostream>
using namespace std;

int arr[21][21];
int num = 0;

int main() {
    int th = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < n-2; j++) {
            for (int k = 0; k < 3; k++) {
                if (arr[i][j+k] == 1) {
                    th++;
                }
                if (arr[i+1][j+k] == 1) {
                    th++;
                }
                if (arr[i+2][j+k] == 1) {
                    th++;
                }
            }
            if (num < th) {
                num = th;
            }
            th = 0;
        }
    }
    cout << num;

    return 0;
}