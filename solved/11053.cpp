#include <bits/stdc++.h>

using namespace std;
int n;
// 수열 저장 배열
int A[1000]; 
// 메모이제이션용 배열
int cache[1001];

int lis(int start) {
    int& ret = cache[start];
    if (ret != -1) return ret;
    ret = 1;
    for (int next = start+1; next < n; next++) {
        if (A[start] < A[next]) {
            ret = max(ret, lis(next) + 1);
        }
    }
    return ret;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    fill_n(cache, 1001, -1);
    for (int i = 0; i < n; i++) {
        lis(i);
    }
    int result = 0;
    for (int j = 0; j < n; j++) {
        result = max(result, cache[j]);
    }
    cout << result;
}