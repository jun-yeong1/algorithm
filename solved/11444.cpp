#include <bits/stdc++.h>

using namespace std;

long long n;
// matrix = ÇÇº¸³ªÄ¡ n=1, temp = Á¦°öÇÑ ÇÇº¸³ªÄ¡ Çà·Ä
vector matrix(2, vector<long long>(2, 0));
vector<vector<long long> > temp;

//Çà·ÄÀÇ °ö¼À
vector<vector<long long> > matrix_mult(vector<vector<long long> >m_1, vector<vector<long long> > m_2) {
    vector result(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] += (m_1[i][k] % 1000000007) * (m_2[k][j] % 1000000007);
            }
        }
    }
    return result;
}

// °ÅµìÁ¦°ö Àç±ÍÀÌ¿ë
vector<vector<long long> > pow(long long m) {
    if (m == 1) return matrix;
    //È¦¼öÀÏ ¶§
    if (m % 2 > 0) return matrix_mult(pow(m-1), matrix);
    vector<vector<long long>> pow_m = pow(m / 2);
    return matrix_mult(pow_m, pow_m);
}


int main(void) {
    cin >> n;
    matrix[0][0] = 0, matrix[0][1] = 1,
    matrix[1][0] = 1, matrix[1][1] = 1;
    temp = pow(n);
    cout << temp[0][1] % 1000000007;
}