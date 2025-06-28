#include <iostream>

using namespace std;

int min_index(int arr[], int n, int start) {
    int result = 10001;
    int index = 0;
    for (int i = start; i < n; i++) {
        if (result > arr[i]) {
            result = arr[i];
            index = i;
        }
    }
    return index;
}
void change(int arr[], int a, int i) {
    int num = 0;
    num = arr[a];
    arr[a] = arr[i];
    arr[i] = num;
}

int main() {
    int n, k = 0;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        change(arr, min_index(arr, n, i), i);
    }
    cout << arr[n-k] << endl;
    return 0;
}