#include <iostream>

using namespace std;

int main()
{
    int num1 = 0, num2 = 0, i = 0;
    for (i = 1; i <= 100; i++) {
        num1 += i;
        if (i % 3 == 0) {
            num2 += i;
        }
    }
    cout << "1~100 사이의 정수합은 " << num1 << "이고" << endl;
    cout << "3의 배수의 합은 " << num2 << "입니다";
}