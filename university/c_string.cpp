#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char password[11];
    cout << "��ȣ �Է�" << endl;
    while(true) {
        cout << "��ȣ>>";
        cin >> password;
        if (strcmp(password, "C++") == 0) {
            cout << "����" << endl;
            break;
        }
        else {
            cout << "��ȣ ����" << endl;
        }
    }
}