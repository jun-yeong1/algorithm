#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    int arr[T];
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < T; i++) {
        int coin[4] = {0, 0, 0, 0};
        if (arr[i] >= 25) {
            coin[0] = coin[0] / 25;
            arr[i] = arr[i] % 25;
        }
        if (arr[i] >= 10) {
            coin[1] /= 10;
            arr[i] %= 10;
        }
        if (arr[i] >= 5) {
            coin[2] /= 5;
            arr[i] %= 5;
        }
        if (arr[i] >= 1) {
            coin[3] /= 1;
            arr[i] %= 1;
        }
        cout << coin[0] << " " << coin[1] << " " << coin[2] << " " << coin[3] << endl;
    }
    return 0;
}