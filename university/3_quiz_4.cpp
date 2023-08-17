#include <iostream>
using namespace std;

class ThreeMatrices {
	int a[3][5] = { {5, 10, 2, 7, 5}, {4, 6, 2, 2, 9}, {1, 9, 2, 8, 4} };
	int b[3][5] = { {5, 2, 7, 4, 5}, {10, 6, 9, 2, 3}, {2, 6, 4, 7, 1} };
	int c[3][5];

public:
	ThreeMatrices() { fill_n(c[0], 15, 0); };
	void printC();
	void biggerC();
	void smallerC();
};
/* printC ����Լ� */
void ThreeMatrices::printC() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}
/* biggerC ����Լ� */
void ThreeMatrices::biggerC() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] <= b[i][j]) {
				c[i][j] = b[i][j];
			}
			else {
				c[i][j] = a[i][j];
			}
		}
	}
}
/* smallerC ����Լ� */
void ThreeMatrices::smallerC() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] <= b[i][j]) {
				c[i][j] = a[i][j];
			}
			else {
				c[i][j] = b[i][j];
			}
		}
	}
}

int main() {
	ThreeMatrices m;
	cout << "initial..." << endl;
	m.printC();
	cout << "bigger..." << endl;
	m.biggerC();
	m.printC();
	cout << "smaller..." << endl;
	m.smallerC();
	m.printC();
}