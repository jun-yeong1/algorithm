#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int start = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (start == 10) {
                start = 1;
            }
            printf("%d ", start);
            start++;
        }
        printf("\n");
    }
    return 0;
}