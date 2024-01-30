#include <bits/stdc++.h>

using namespace std;

unsigned int S[21];

void add(int num) {
    S[num] |= (1 << num);
}
void remove(int num) {
    S[num] &= ~(1 << num);
}
void check(int num) {
    if (S[num] & (1 << num)) cout << 1 <<'\n';
    else cout << 0 << '\n';
}
void toggle(int num) {
    S[num] ^= (1 << num);
}
void all() {
    for (int i = 1; i <= 20; i++) {
        S[i] |= (1 << i);
    }
}
void empty() {
    for (int i = 1; i <= 20; i++) {
        S[i] -= (1 << i);
    }
}
 
int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {\
        string a; int b;
        cin >> a;
        if (a != "all" && a != "empty") {
            cin >> b;
        }
        if (a == "add") add(b);
        else if (a == "remove") remove(b);
        else if (a == "check") check(b);
        else if (a == "toggle") toggle(b);
        else if (a == "all") all();
        else if (a == "empty") empty();
    }
}