#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "";
    string b = "";
    string result = "00:00:00";
    cin >> a;
    cin >> b;
    int first = 0; int second = 0; int third = 0;
    int half = 0;

    int a_first = (a[6]-'0') * 10 + (a[7]-'0');
    int b_first = (b[6]-'0') * 10 + (b[7]-'0');
    if (a_first > b_first) {
        first = 60 - a_first + b_first;
        half = 1; // 반올림
    } else if (a_first < b_first) {
        first = b_first - a_first;
    }
    int a_second = (a[3]-'0') * 10 + (a[4]-'0');
    int b_second = (b[3]-'0') * 10 + (b[4]-'0');
    if ((a_second+half) > b_second) {
        second = 60 - a_second + b_second - half;
        half = 1;
    } else if ((a_second+half) < b_second) {
        second = b_second - a_second - half;
        half = 0;
    }
    int a_third = (a[0]-'0') * 10 + (a[1]-'0');
    int b_third = (b[0]-'0') * 10 + (b[1]-'0');
    if ((a_third+half) > b_third) {
        third = 24 - a_third + b_third - half;
    }
    if ((a_third+half) == b_third) {
        third = 0;
    } else if ((a_third+half) < b_third) {
        third = b_third - a_third - half;
    }

    if (first >= 10) {
        result[6] = (char)(first / 10 + 48);
        result[7] = (char)(first % 10 + 48);
    } else if (first != 0){
        result[6] = '0';
        result[7] = (char)(first % 10 + 48);
    }
    if (second >= 10) {
        result[3] = (char)(second / 10 + 48);
        result[4] = (char)(second % 10 + 48);
    } else if (second != 0){
        result[3] = '0';
        result[4] = (char)(second % 10 + 48);
    }
    if (third >= 10) {
        result[0] = (char)(third / 10 + 48);
        result[1] = (char)(third % 10 + 48);
    } else if (third != 0){
        result[0] = '0';
        result[1] = (char)(third % 10 + 48);
    }
    cout << result << endl;
}