#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[10];
    char password[10];
    char password_two[10];
    cout << "이름 입력: ";
    cin >> name;
    cout << "암호 입력: ";
    cin >> password;
    cout << "다시 입력: ";
    cin >> password_two;
    if (strcmp(password, password_two) == 0) {
        cout << name << "님께서 로그인하셨습니다." << endl;
    }
    else {
        cout << name << "님, 다시 입력하세요." << endl;
    }
}