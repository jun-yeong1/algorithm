#include <iostream>

using namespace std;

void change(int arr[5], int a, int b) {
    int n = arr[a];
    arr[a] = arr[b];
    arr[b] = n;
}

int main() {
    int avg = 0; int middle = 0;
    int arr[5]; 
    for (int i = 0; i < 5; i++) {
        cin >> arr[i]; 
    }
    for (int i = 0; i < 5; i++) {
        avg += arr[i]; 
    }
    avg = avg / 5;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[j] > arr[j+1]) {
                change(arr, j, j+1);
            }
        }
    }
    middle = arr[2];
    cout << avg << endl;
    cout << middle << endl;
    return 0;
}