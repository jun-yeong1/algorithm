#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N+1];
    arr[0] = 0;
    // arr[0] 이 숫자 1임
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }
    // 3부터
    for (int i = 2; i <= N; i++) {
        if (i%3 == 0) {
            arr[i] = min(arr[i], arr[i/3]);
        }
        if (i%2 == 0) {
            arr[i] = min(arr[i], arr[i/2]);
        }
        arr[i] = min(arr[i], arr[i-1]) + 1;
    }
    printf("%d\n", arr[N]-1);
    int current = N;

    while (current != 0) {
        printf("%d ", current);
        if (current%3 == 0 && arr[current] - 1 == arr[current/3]) {
            current /= 3;
        } else if (current%2 == 0 && arr[current] - 1 == arr[current/2]) {
            current /= 2;
        } else if (arr[current] - 1 == arr[current-1]) {
            current -= 1;
        }
    }
}