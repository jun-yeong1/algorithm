#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    string password;
    string password_two;
    cout << "�̸� �Է�: ";
    cin >> name;
    cout << "��ȣ �Է�: ";
    cin >> password;
    cout << "�ٽ� �Է�: ";
    cin >> password_two;
    if (password == password_two) {
        cout << name << "�Բ��� �α����ϼ̽��ϴ�." << endl;
    }
    else {
        cout << name << "��, �ٽ� �Է��ϼ���." << endl;
    }
}