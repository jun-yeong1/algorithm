#include <iostream>
#include "iu.h"
#include "gong.h"
using namespace std;

int main() {
    cout << "iu의 세 변수\n";
    cout << iu::aout << " " << iu::bout << " " << iu::cout << endl;
    // 중복되면 iu:: 붙이기

    cout << "gong의 변수 한 개\n";
    cout << gong::a << endl;
}