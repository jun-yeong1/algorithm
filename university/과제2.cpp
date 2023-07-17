#include <iostream>

using namespace std;

int main() {
    int kor, eng, mat, sum = 0;
    cout << "국영수 점수 입력: ";
    cin >> kor >> eng >> mat; 
    double num = kor + eng + mat;
    cout << "합계 = " << kor + eng + mat << "\n";
    double result = num / 3;
    cout << "평균 = " << result;
}