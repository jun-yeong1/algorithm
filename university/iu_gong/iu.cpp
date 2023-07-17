#include <iostream>
#include "gong.h"
using std::cout;

namespace iu {
    int f() {
        cout << "iu.f() \n";
        return 1;
    }

    void m() {
        cout << "iu m() \n";
        f();
        gong::f();
    }
}    