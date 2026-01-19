#include <iostream>
#include <queue>
#include <vector>

#define MAX 1000001

using namespace std;

bool visited[MAX];
int graph[MAX] = {0,};

int F, S, G, U, D;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if (x+U <= F && !visited[x+U]) {
            q.push(x+U);
            visited[x+U] = true;
            graph[x+U] = graph[x]+1;
        }
        if (x-D > 0 && !visited[x-D]) {
            q.push(x-D);
            visited[x-D] = true;
            graph[x-D] = graph[x]+1;
        }
    }
}

int main() {
    cin >> F >> S >> G >> U >> D;
    bfs(S);
    if (visited[G]) {
        cout << graph[G] << endl;
    } else {
        cout << "use the stairs" << endl;
    }

    return 0;
}