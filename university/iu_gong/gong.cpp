#include <iostream>
#include "iu.h"
using std::cout;

namespace gong {
    int f(){
        cout << "gong f() \n";
        return -1;
    }
    int g(){
        cout << "gong g() \n";
        f();
        iu::f();
        return 0;
    }
}