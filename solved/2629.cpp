#include <bits/stdc++.h>

using namespace std;
// ch = ?? ??
int ch;
int ch_array[31];
bool cache[40500][31];

void check(int weight, int chu) {
    if (chu > ch || cache[weight][chu]) return;
    cache[weight][chu] = true;
    // ? ??
    check(weight, chu+1);
    // ??? ??
    check(abs(weight - ch_array[chu]), chu+1);
    // ?? ??
    check(weight + ch_array[chu], chu+1);
}

int main(void) {
    cin >> ch;
    for (int i = 0; i < ch; i++) {
        cin >> ch_array[i];
    }
    check(0, 0);
    int cicle;
    cin >> cicle;
    for (int i = 0; i < cicle; i++) {
        int check_ci;
        cin >> check_ci;
        if (cache[check_ci][ch]) cout << "Y" << " ";
        else cout << "N" << " "; 
    }
}