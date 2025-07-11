#include <iostream>
#define MAX 10000
using namespace std;
int N, K;
int arr[10000];

int min(int start) {
    int min = 1000001;
    int num = 0;
    for (start; start < N; start++) {
        if (arr[start] < min) {
            min = arr[start];
            num = start;
        }
    }
    return num;
}
void change(int a, int b) {
    int tmp = 0;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void sort() {
    for (int i = 0; i < N; i++) {
        change(min(i), i);
    }
}
int main() {
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort();
    for (int i = 0; i < N; i++) {
        cout << arr[i];
    }

    return 0;
}