#include <iostream>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    int arr[N][N];
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int in, out, num;
        cin >> in >> out >> num;
        arr[in][out] = num;
    }
    int box = 0;
    int result = 0;
    for (int i = 1; i <= N; i++) {
        // 받기(박스 내리기)
        for (int k = 1; k < i; k++) {
            if (arr[k][i] > 0) {
                if (box <= arr[k][i]) {
                    result += box;
                    box = 0;
                } else {
                    result += arr[k][i];
                    box -= arr[k][i];
                }
            }
        }
        // 보내기(박스 추가)
        for (int j = i+1; j <= N; j++) {
            if (box + arr[i][j] >= 40) box = 40;
            else {
                box += arr[i][j];
            }
        }
    }
    cout << result << endl;
    
    return 0;
}