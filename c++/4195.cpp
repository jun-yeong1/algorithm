#include <iostream>
#include <unordered_map>

#define MAX 200001

using namespace std;

int parent[MAX];
// 친구수
int cnt[MAX];

int union_find(int name) {
    if (parent[name] == name) {
        return name;
    }
    return parent[name] = union_find(parent[name]);
}
// 친구 수 바로 반환
int join(int a, int b) {
    int pa = union_find(a);
    int pb = union_find(b);
    if (pa == pb) return cnt[pa];
    if (cnt[pa] < cnt[pb]) swap(pa, pb);
    parent[pb] = pa;
    cnt[pa] += cnt[pb];
    return cnt[pa];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    cin >> n;
    while(n--) {
        int f;
        cin >> f;
        unordered_map<string, int> id;
        int idx = 0;
        for (int i = 0; i < MAX; i++) {
            parent[i] = i;
            cnt[i] = 1;
        }
        while (f--) {
            string a, b;
            int a_index, b_index;
            cin >> a >> b;
            if (!id.count(a)) id[a] = idx++;
            if (!id.count(b)) id[b] = idx++;
            printf("%d\n", join(id[a], id[b]));
        }
    }
    return 0;
}