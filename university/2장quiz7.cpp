#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[10];
    char password[10];
    char password_two[10];
    cout << "�̸� �Է�: ";
    cin >> name;
    cout << "��ȣ �Է�: ";
    cin >> password;
    cout << "�ٽ� �Է�: ";
    cin >> password_two;
    if (strcmp(password, password_two) == 0) {
        cout << name << "�Բ��� �α����ϼ̽��ϴ�." << endl;
    }
    else {
        cout << name << "��, �ٽ� �Է��ϼ���." << endl;
    }
}