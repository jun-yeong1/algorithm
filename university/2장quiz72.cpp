#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    string password;
    string password_two;
    cout << "이름 입력: ";
    cin >> name;
    cout << "암호 입력: ";
    cin >> password;
    cout << "다시 입력: ";
    cin >> password_two;
    if (password == password_two) {
        cout << name << "님께서 로그인하셨습니다." << endl;
    }
    else {
        cout << name << "님, 다시 입력하세요." << endl;
    }
}