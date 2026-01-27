#include <iostream>
#include <vector>

#define MAX 201

using namespace std;

int n, m;
int city[MAX];
int depth[MAX];
vector<int> m_city;

int find(int num) {
    if (city[num] == num) {
        return num;
    }
    return city[num] = find(city[num]);
}

void join (int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) return;
    if (depth[pa] > depth[pb]) {
        city[pb] = pa;
    } else if (depth[pa] < depth[pb]) {
        city[pa] = pb;
    }
    else if (depth[pa] == depth[pb]) {
        city[pa] = pb;
        depth[pb]++;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> m;

    for (int i = 1; i <= MAX; i++) {
        city[i] = i;
        depth[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                join(i, j);
            }
        }
    }
    while (m--) {
        int num;
        cin >> num;
        m_city.push_back(num);
    }

    bool yes_no = true;
    int root = find(m_city[0]);
    for(int i : m_city) {
        if (root != find(i)) {
            yes_no = false;
            break;
        }
    }
    if (yes_no) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}