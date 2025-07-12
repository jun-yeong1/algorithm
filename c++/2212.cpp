#include <iostream>
#define MAX 10000
using namespace std;

int N, K;
int sensor[10000];
int dis[9999];

int min(int arr[], int start) {
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
int max(int arr[], int start) {
    int max = -1;
    int num = 0;
    for (start; start < N-1; start++) {
        if (arr[start] > max) {
            max = arr[start];
            num = start;
        }
    }
    return num;
}
void change(int arr[], int a, int b) {
    int tmp = 0;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
void min_sort() {
    for (int i = 0; i < N; i++) {
        change(sensor, min(sensor, i), i);
    }
}
void max_sort() {
    for (int i = 0; i < N-1; i++) {
        change(dis, max(dis, i), i);
    }
}
void distance() {
    for (int i = 0; i < N-1; i++) {
        dis[i] = sensor[i+1] - sensor[i]; 
    }
}
int main() {
    int result = 0;
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++) {
        cin >> sensor[i];
    }
    min_sort();
    distance();
    max_sort();

    for (int i = K-1; i < N-1; i++) {
        result += dis[i];
    }
    cout << result;
    return 0;
}
// 앞 뒤 센서의 거리값을 정렬하고 K 갯수만큼 분배하여야 하기에
// K-1 개의 큰 거리값을 빼고 나머지를 더해주면 해결