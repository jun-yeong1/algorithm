#include <iostream>

#define MAX 1000000
using namespace std;

int n, m;
int graph[MAX];

int find(int num) {
    if (graph[num] == num) {
        return num;
    }
    return graph[num] = find(graph[num]);
}

void join(int a, int b) {
    int parent_a = find(a);
    int parent_b = find(b);
    if (parent_a != parent_b) {
        graph[parent_a] = parent_b; 
    }
}
bool in_group(int a, int b) {
    int parent_a = find(a);
    int parent_b = find(b);
    if (parent_a != parent_b) {
        return false;
    } else {
        return true;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < MAX; i++) {
        graph[i] = i;
    }
    while (m--) {
        int s, a, b;
        cin >> s >> a >> b;
        if (s == 0) {
            join(a, b);
        } else if (s == 1) {
            if (in_group(a, b)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }

    return 0;
}