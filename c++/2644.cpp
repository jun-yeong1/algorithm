#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[100];
vector<int> graph[100];
int result = 0;

int dfs(int start, int parent, int other) {
    visited[start] = parent;
    int p = 0;
    if (graph[start].size() < 1) {
        return 0;
    } else {
        p = graph[start][0];
        parent++;

        if (p != other && visited[p] == 0) {
            dfs(p, parent, other);
        } else if (p == other){
            result = parent;
        } else if (visited[p] != 0) {
            result = visited[p] + parent;
        }
    }
    return result;
}
int main(void) {
    int n, m;
    cin >> n; // 사람 수

    fill_n(visited, 100, 0); // 배열 초기화

    // 계산 대상 번호 둘
    int person_1, person_2;
    cin >> person_1 >> person_2;

    cin >> m; // 관계 수
    for (int i = 0; i < m; i++) {
        int x, y = 0;
        scanf("%d %d", &x, &y);
        graph[y].push_back(x); // 자식 -> 부모
    }
    int result_1 = dfs(person_1, 0, person_2);
    if (result_1 == 0) {
        int result_2 = dfs(person_2, 0, person_1);
        if (result_2 != 0) {
            cout << result_2 << endl;
        } else {
            cout << "-1" << endl;
        }
    } else {
        cout << result_1 << endl;
    }

    return 0;
}