#include <bits/stdc++.h>
#define MAX_N 5
using namespace std;
int n;
long long b;
// matrix = Çà·Ä ¿øº», temp = Á¦°ö Áß Çà·Ä
vector matrix(MAX_N, vector<int>(MAX_N, 0));
vector<vector<int> > temp;

//Çà·ÄÀÇ °ö¼À
vector<vector<int> > matrix_mult(vector<vector<int> >m_1, vector<vector<int> > m_2) {
    vector result(MAX_N, vector<int>(MAX_N, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += (m_1[i][k] % 1000) * (m_2[k][j] % 1000);
            }
        }
    }
    return result;
}

// °ÅµìÁ¦°ö Àç±ÍÀÌ¿ë
vector<vector<int> > pow(long long m) {
    //È¦¼öÀÏ ¶§
    if (m == 1) return matrix;
    if (m % 2 > 0) return matrix_mult(pow(m-1), matrix);
    vector<vector<int>> pow_m = pow(m / 2);
    return matrix_mult(pow_m, pow_m);
}


int main(void) {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    temp = pow(b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << temp[i][j] % 1000 << " ";
        }
        cout << '\n';
    }
}