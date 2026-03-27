#include <iostream>
#include <cstring>

using namespace std;
// 점수 배열
int peo[100001];

int greed(int n) {
    int result = 1;
    //t_b : 타켓 면접점수
    int t_b = peo[1];
    for (int i = 2; i <= n; i++) {
        // 면접 점수가 자신보다 높은 것으로 갱신
        // 갱신된 점수로 아래 비교
        if (peo[i] < t_b) {
            result++;
            t_b = peo[i]; 
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            // 입력을 정렬된 상태로 만들기
            // 서류 정렬시 면접만으로 비교
            peo[a] = b;
        }
        cout << greed(n) << endl; // 그리디
    }

    return 0;
}