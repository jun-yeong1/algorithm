#include <bits/stdc++.h>

using namespace std;

// 높이 저장 배열
vector<long long> h;

long long solve(int left, int right) {
    if (left == right) return h[left];
    int mid = (left + right) / 2;
    // 분할 정복
    long long ret = max(solve(left, mid), solve(mid+1, right));
    int le = mid, ri = mid + 1;
    // 직사각형의 높이는 선택된 곳에서 가장 작은 것
    long long height = min(h[le], h[ri]);
    // mid, mid+1이 최대인 경우
    ret = max(ret, height * 2);
    while (left < le || ri < right) {
        // 높이가 큰 쪽으로 확장
        if (ri < right && (le == left || h[le-1] < h[ri+1])) {
            // 오른쪽이 높이가 클 때
            ++ri;
            // 가장 작은 높이 선택
            height = min(height, h[ri]);
        }
        else {
            // 왼쪽이 높이가 클 때
            --le;
            // 가장 작은 높이 선택
            height = min(height, h[le]);
        }
        // 사각형 넓이
        ret = max(ret, height * (ri - le + 1));
    }
    return ret;
}

int main(void) {
    int n, a;
    cin >> n;
    while (n != 0) {
        h.clear();
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            h.push_back(a);
        }
        cout << solve(0, n-1) << '\n';
        cin >> n;
    }
    return 0;
}