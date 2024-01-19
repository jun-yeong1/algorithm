#include <bits/stdc++.h>

using namespace std;

int n, k;
int volume[100], need[100];
int cache[100001][100];
// capacity 남은 용량, item 물품 수
int pack(int capacity, int item) {
    // 물품을 다 넣을 경우
    if (item == n) return 0;
    int& ret = cache[capacity][item];
    if (ret != -1) return ret;
    // 물품 안 넣는 경우
    ret = pack(capacity, item+1);
    // 물품 넣을 경우 (남은 용량이 크거나 같을 때)
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
    // fill [행 크기 최대-1][열 크기 최대]
    fill(&cache[0][0], &cache[100000][100], -1);
    cout << pack(k, 0);
}