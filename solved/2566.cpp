#include <bits/stdc++.h>

using namespace std;
int graph[9][9];
int max_n = -1;
int x, y;
int main() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> graph[i][j];
    }
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (graph[i][j] > max_n) {
        max_n = graph[i][j];
        x = (i + 1), y = (j + 1);
      } 
    }
  }
  cout << max_n << endl;
  cout << x << ' ' << y;
}