#include <iostream>

using namespace std;

void back(bool visited[], int arr[], int n, int m, int num) {
    if (num == m) {
        for (int i = 0; i < m-1; i++) {
            printf("%d ", arr[i]);
        }
        printf("%d\n", arr[m-1]);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (num == m-1 && visited[i] == false) {
            visited[i] = true;
            arr[num] = i+1;
            num++;
            back(visited, arr, n, m, num);
            num--;
            visited[i] = false;
        } else {
            arr[num] = i+1;
            num++;
            back(visited, arr, n, m, num);
            num--;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    bool visited[n];
    int arr[m];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    back(visited, arr, n, m, 0);

    return 0;
}