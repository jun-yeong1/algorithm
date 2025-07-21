#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<vector<int>>arr(N+1, vector<int>(N+1, 0));
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int in, out, num = 0;
        cin >> in >> out >> num;
        arr[in][out] = num;
    }
    int box = 0; // 현재 들고 있는 박스 개수
    int result = 0; // 마을에 내리 박스 총 개수
    // i = 현재 위치의 마을
    for (int i = 1; i <= N; i++) {
        // 받기(박스 내리기) k는 i 보다 작은 마을
        for (int k = 1; k < i; k++) {
            if (arr[k][i] != 0) {
                if (box <= arr[k][i]) {
                    result += box;
                    box = 0;
                } else {
                    result += arr[k][i];
                    box -= arr[k][i];
                }
            }
        }
        // 보내기(박스 추가) j는 i보다 큰 마을들
        for (int j = i+1; j <= N; j++) {
            if (arr[i][j] != 0) {
                box += arr[i][j];
            }
        }
        if (box > C) {
            box = C;
        }
    }
    cout << result << endl;
    
    return 0;
}
// 먼저 현재 위치의 마을에 내려야할 물건을 내린 뒤
// 이 마을에서 보낼 물건을 싣는다
// 배열 초기화를 해야함