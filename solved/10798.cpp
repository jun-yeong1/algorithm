#include <bits/stdc++.h>

using namespace std;

int main() {
    char array[5][16] = {{'\0', }, };
    for (int i = 0; i < 5; i++) {
        cin >> array[i];
    } 
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
            if (array[j][i] != '\0') {
                cout << array[j][i];
            } 
        }
    } 
}