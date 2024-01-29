#include <bits/stdc++.h>

using namespace std;

int n;
int S[1000], cache[1000], choices[1000];
vector<int> re;

int lis(int start) {
    int& ret = cache[start];
    if (ret != -1) return ret;
    ret = 1;
    int best = -1;
    for (int next = start+1; next < n; next++) {
        if (start == -1 || S[start] < S[next]) {
            int cand = lis(next) + 1;
            if (cand > ret) {
                ret = cand;
                best = next;
            }
        }
    }
    choices[start] = best;
    return ret;
}
void output(int start, vector<int>& seq) {
    if (start != -1) seq.push_back(S[start]);
    int next = choices[start];
    if (next != -1) output(next, seq);
}
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    fill_n(cache, 1000, -1);
    fill_n(choices, 1000, -1);
    int result = 0;
    int re_i = 0;
    for (int i = 0; i < n; i++) {
        if (result < lis(i)) {
            result = lis(i);
            re_i = i;
        }
    }
    cout << result << '\n';
    output(re_i, re);
    for (int i = 0; i < result; i++) {
        cout << re[i] << " ";
    }
}