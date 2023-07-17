#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char password[11];
    cout << "암호 입력" << endl;
    while(true) {
        cout << "암호>>";
        cin >> password;
        if (strcmp(password, "C++") == 0) {
            cout << "종료" << endl;
            break;
        }
        else {
            cout << "암호 오류" << endl;
        }
    }
}