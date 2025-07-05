#include <iostream>

using namespace std;

int min_num(int a, int b, int c) {
    if (a >= b) {
        if (b >= c) {
            return c;
        } else {
            return b;
        }
    } else {
        if (a >= c) {
            return c;
        } else {
            return a;
        }
    }
}

int main () {
    int result = 0;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;
    for (int i = 0; i < n-2; i++) {
        if (arr[i] == 0 || arr[i+1] == 0 || arr[i+2] == 0) continue;
        int a = min_num(arr[i], arr[i+1], arr[i+2]);
        result += a * 7;
        arr[i] -= a; arr[i+1] -= a; arr[i+2] -= a;
    }
    for (int i = 0; i < n-1; i++) {
        if (arr[i] == 0 || arr[i+1] == 0) continue;
        int b = 0;
        if (arr[i] > arr[i+1]) {
            b = arr[i+1];
            arr[i] -= b; arr[i+1] -= b;
            result += b * 5;
        } else {
            b = arr[i];
            arr[i] -= b; arr[i+1] -= b;
            result += b * 5;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) continue;
        result += arr[i] * 3;
    }
    cout << result;
    return 0;
}
// 2부터 먼저 지워야 하는 케이스
4
1 2 1 1
// 정답 : 12
    
// 2부터 먼저 지워야 하는 케이스
4
2 4 2 2 
// 정답 : 24
    
// 2부터 먼저 지워야 하는 케이스
4
1 4 3 3 
// 정답 : 26
    
// 3부터 먼저 지워야 하는 케이스
4
1 3 3 1
// 정답 : 19
    
// 2, 3을 연속해서 지워야 하는 케이스
4
2 5 4 2
// 정답 : 31
    
// 여러 가지 숫자 케이스
7
2 3 2 3 3 2 1 
// 정답 : 38