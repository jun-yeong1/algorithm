#include <bits/stdc++.h>

using namespace std;

// ���� ���� �迭
vector<long long> h;

long long solve(int left, int right) {
    if (left == right) return h[left];
    int mid = (left + right) / 2;
    // ���� ����
    long long ret = max(solve(left, mid), solve(mid+1, right));
    int le = mid, ri = mid + 1;
    // ���簢���� ���̴� ���õ� ������ ���� ���� ��
    long long height = min(h[le], h[ri]);
    // mid, mid+1�� �ִ��� ���
    ret = max(ret, height * 2);
    while (left < le || ri < right) {
        // ���̰� ū ������ Ȯ��
        if (ri < right && (le == left || h[le-1] < h[ri+1])) {
            // �������� ���̰� Ŭ ��
            ++ri;
            // ���� ���� ���� ����
            height = min(height, h[ri]);
        }
        else {
            // ������ ���̰� Ŭ ��
            --le;
            // ���� ���� ���� ����
            height = min(height, h[le]);
        }
        // �簢�� ����
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