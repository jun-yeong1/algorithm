#include <iostream>
#include <cstring>
using namespace std;

int cache[31][31];
// 해당 문제는 원래 mCn = m! / n!(m-n)! 로 푸는 문제
// n = 남은 n다리 수, m = 남은 m다리 수
int bridge(int n, int m) {
    if (n == 0) return 1;
    if (n == m) return 1;
    if (cache[n][m] != 0) return cache[n][m];
    int result = 0;
    for (int i = 1; i <= m-n+1; i++) {
        result += bridge(n-1, m - i);
    }
    cache[n][m] = result;
    return result;
}

int main() {
    int T;
    cin >> T;
    memset(cache, 0, sizeof(cache));
    for (int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;
        cout << bridge(n, m) << endl;
    }

    return 0;
}