#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > matrix(500);
int min_mt[250];
int cache[500][500];
int mult_result(int start, int end) {
    return matrix[start].first * matrix[end].first * matrix[end].second;
}
int mult(int start, int end) {
    if (start == end) return 0;
    int& ret = cache[start][end];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int i = start; i <= end; i++) {
        ret = min(ret, mult(start, i) + mult(i+1, end) 
        + mult_result(i, i+1));
    }
    return ret;
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> matrix[i].first >> matrix[i].second;
    }
    fill(&cache[0][0], &cache[499][500], -1);
    cout << mult(0, n);
}