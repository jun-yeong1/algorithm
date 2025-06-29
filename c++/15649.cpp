#include <iostream>
#include <stdlib.h>

using namespace std;

void back(bool visited[], int arr[], int n, int m, int num) {
    if (num == m) {
        for (int i = 0; i < m-1; i++) {
            cout << arr[i] << " ";
        }
        cout << arr[m-1] << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            arr[num] = i+1;
            num++;
            back(visited, arr, n, m, num);
            visited[i] = false;
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
    for (int i = 0; i < n; i++) {
        arr[0] = i+1;
        back(visited, arr, n, m, 1);
    }
}