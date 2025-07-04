#include <iostream>
#include <algorithm>
#define MAX 15
using namespace std;

int board[MAX]; // board[행] = 값(열) 반대도 됨
int n;
int cnt;

void path(int y) {
	int ko;
	if(y == n) {
		cnt++;
		return;
	}
	for(int i = 0; i < n; i++) {
		ko = 1;
		for(int j = 0; j < y; j++) {
            // 같은 행이나 열에 있는지, 대각선에 있는지(x1-x2 = y2-y1)
			if(board[j] == i || abs(y-j) == abs(i-board[j])) {
				ko = 0;
				break;
			}
		}
		if(ko) {
			board[y] = i;
			path(y+1);
		}
	}
}

int main() {
    cin >> n;
    cnt = 0;
    path(0);

    cout << cnt << '\n';

	return 0;
}