#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int hour, min, cook;
    cin >> hour >> min >> cook;

    min = min + cook;
    if (min >= 60) {
        hour += min / 60;
        min = min % 60;
    }
    if (hour >= 24) {
        hour %= 24;
    }
    cout << hour << " " << min;
}