#include <iostream>
#include <string>
using namespace std;

int main() {
    string question[] = {"��", "�����", "�⸰", "�ڳ���", "ǥ��"};
    string answer[] = {"dog", "cat", "giraffe", "elephant", "leopard"};
    string ox;
    int score(0);

    cout << "���ܾ�� �ٲټ���." << endl;
    for (int i = 0; i < 5; i++) {
        string a;
        cout << question[i] << ": ";
        getline(cin, a);
        if (a == answer[i]) {
            ox += "O";
            score += 20;
        }
        else {
            ox += "X";
        }
    }
    cout << "==> " << ox << " " << score << " ���Դϴ�." << endl;
}