#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char a[100] = "�ȳ��ϼ���?";
    char b[100] = "������ �� ������.";
    char c[100] = "�ȳ��� �輼��!";

    cout << "�Լ� ���" << endl;
    cout << strlen(a) << " " << strlen(b) << " " << strlen(c) << endl;

    cout << "�ݺ������� ���" << endl;
    for (int i = 0; i < 100; i++) {
        if (a[i] == '\0') {
            cout << i << " ";
            break;
        }
    }
    for (int i = 0; i < 100; i++) {
        if (b[i] == '\0') {
            cout << i << " ";
            break;
        }
    }
    for (int i = 0; i < 100; i++) {
        if (c[i] == '\0') {
            cout << i;
            break;
        }
    }
}