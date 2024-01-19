#include <bits/stdc++.h>

using namespace std;
// sum�� 1���� �� �ڸ������� ��
int file[501], sum[501];
int cache[501][501];

int file_sum(int start, int end) {
    if (start == end) return 0;
    int& ret = cache[start][end];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int i = start; i < end; i++) {
        // start-i������ �ּ� + i+1���� end���� �ּ� + end�� - start-1��
        ret = min(ret, file_sum(start, i) + file_sum(i+1, end) + sum[end]-sum[start-1]);
    }
    return ret;
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> file[j];
            sum[j] = sum[j-1] + file[j];
        }
        fill(&cache[0][0], &cache[500][501], -1);
        cout << file_sum(1, k) << '\n';
    }
}