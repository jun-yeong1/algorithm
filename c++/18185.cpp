#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int result = 0;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) continue;
        int num = arr[i];
        arr[i] = 0;
        result += num * 3;
        
        if (i+1 >= n) continue;
        num = min(num, arr[i+1]);
        arr[i+1] -= num;
        result += num * 2;

        if (i+2 >= n) continue;
        if (num + arr[i+1] > arr[i+2]) { // 원래 arr[i+1] 크기와 비교
            // 앞에서 뺀 후의 arr[i+1]가 arr[i+2] 보다 커야
            // 3번째도 arr[i]의 수를 빼주어야 함
            // 만약 같거나 작은 경우는 arr[i+2]는 빼지 않음
            num = min(num, max(0, arr[i+2]-arr[i+1]));
        }
        arr[i+2] -= num;
        result += num * 2;
    }
    cout << result;
    return 0;
}
// // 2부터 먼저 지워야 하는 케이스
// 4
// 1 2 1 1
// // 정답 : 12
    
// // 2부터 먼저 지워야 하는 케이스
// 4
// 2 4 2 2 
// // 정답 : 24
    
// // 2부터 먼저 지워야 하는 케이스
// 4
// 1 4 3 3 
// // 정답 : 26
    
// // 3부터 먼저 지워야 하는 케이스
// 4
// 1 3 3 1
// // 정답 : 19
    
// // 2, 3을 연속해서 지워야 하는 케이스
// 4
// 2 5 4 2
// // 정답 : 31
    
// // 여러 가지 숫자 케이스
// 7
// 2 3 2 3 3 2 1 
// // 정답 : 38