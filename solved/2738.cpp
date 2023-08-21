#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  getchar();
  int array[n * 2][m];
  int result[n][m];
  for (int i = 0; i < (n * 2); i++) {
    for (int j = 0; j < m; j++) {
      cin >> array[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      result[i][j] = array[i][j] + array[i + n][j]; 
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << result[i][j];
      cout << ' ';
    }
    cout << endl;
  }
}