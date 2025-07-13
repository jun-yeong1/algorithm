#include <iostream>

using namespace std;

int main () {
    int a, b, c = -1;
    while(1) {
        int max = -1;
        int plus = 0;
        cin >> a >> b >> c;
        if (a == 0 && b == 0; c == 0) {
            break;
        }
        if (a >= b) {
            if (a >= c) {max = a; plus = b + c;}
            else if (c >= b) {max = c; plus = a + b;}
            else {max = b; plus = a + c;}
        } else {
            if (b >= c) {max = b; plus = a + c;}
            else if (c >= a){max = c; plus = a + b;}
            else {max = a; plus = b + c;}
        }
        if (a == b && b == c) {
            printf("Equilateral\n");
        } else if (max >= plus) {
            printf("Invalid\n");
        } else if ((a == b && a != c) || (b == c && a != b) || (a == c && a != b)) {
            printf("Isosceles\n");
        } else if (a != b && b != c && a != c) {
            printf("Scalene\n");
        }
    }
    return 0;
}