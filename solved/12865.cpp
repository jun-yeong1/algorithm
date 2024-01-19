#include <bits/stdc++.h>

using namespace std;

int n, k;
int volume[100], need[100];
int cache[100001][100];
// capacity ���� �뷮, item ��ǰ ��
int pack(int capacity, int item) {
    // ��ǰ�� �� ���� ���
    if (item == n) return 0;
    int& ret = cache[capacity][item];
    if (ret != -1) return ret;
    // ��ǰ �� �ִ� ���
    ret = pack(capacity, item+1);
    // ��ǰ ���� ��� (���� �뷮�� ũ�ų� ���� ��)
    if (capacity >= volume[item]) {
        ret = max(ret, pack(capacity-volume[item], item+1) + 
                need[item]);
    }
    return ret;
}
int main(void) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> volume[i] >> need[i];
    }
    // fill [�� ũ�� �ִ�-1][�� ũ�� �ִ�]
    fill(&cache[0][0], &cache[100000][100], -1);
    cout << pack(k, 0);
}