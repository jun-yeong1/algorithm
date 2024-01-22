#include <bits/stdc++.h>

using namespace std;
// ch = ?? ??
int ch;
int ch_array[30];
int cache[40001][40001];

int check(int left, int right, int chu) {
    if (left == right) return 1;
    if (chu == ch && left != right) return 0;
    int& ret = cache[left][right];
    if (ret != -1) return ret;
    ret = chu;
    check(left, right, chu+1);
    check(left+ch_array[chu], right, chu+1);
    check(left, right+ch_array[chu], chu+1);
}

int main(void) {
    cin >> ch;
    for (int i = 0; i < ch; i++) {
        cin >> ch_array[i];
    }
    fill(&cache[0][0], &cache[40000][40001], -1);
    int cicle;
    cin >> cicle;
    for (int i = 0; i < cicle; i++) {
        int check_ci;
        cin >> check_ci;
        cout << check(check_ci, 0, 0) << " ";
    }
}