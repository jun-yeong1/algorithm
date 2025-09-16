#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    
    int x, y = 0;
    x = (c*e - f*b) / (a*e - d*b);
    y = (c*d - f*a) / (b*d - e*a); 

    cout << x << " " << y << endl;

    return 0;
}