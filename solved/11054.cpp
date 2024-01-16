#include <bits/stdc++.h>

using namespace std;

int n;
int A[1000];
// cache1 = n부터 0까지
// cache2 = 0부터 n까지
int cache1[1000], cache2[1000];
// 오름차순
int lis1(int start) {
    int& ret = cache1[start];
    if (ret != 0) return ret;
    ret = 1;
    for (int next = start-1; next >= 0; next--) {
        if (A[start] > A[next]) {
            ret = max(ret, lis1(next) + 1);
        } 
    }
    return ret;
}
// 내림차순 3 2 1 순
int lis2(int start) {
    int& ret = cache2[start];
    if (ret != 0) return ret;
    ret = 1;
    for (int next = start+1; next < n; next++) {
        if (A[start] > A[next]) {
            ret = max(ret, lis2(next) + 1);
        }
    }
    return ret;
}
int main(void) {
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> A[i];
    }
    fill_n(cache1, 1000, 0);
    fill_n(cache2, 1000, 0);
    for (int i = 0; i < n; i++) {
        lis1(n-i);
        lis2(i);
    }
    int result = 1;
    for (int i = 0; i < n; i++) {
        cout << cache2[i] << " ";
        if (cache1[i] == 0 || cache2[i] == 0) {
            result = max(result, cache1[i] + cache2[i]);
        } else {
            result = max(result, cache1[i] + cache2[i]-1);
        }
        
    }
    //cout << result;
}