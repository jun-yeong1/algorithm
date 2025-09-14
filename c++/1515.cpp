#include <iostream>

using namespace std;

int main() {
    string N;
    cin >> N;
    int index, result = 1;
    while(index != N.length()) {
        string num = to_string(result);
        for (int i = 0; i < num.length(); i++) {
            if (N[index] == num[i]) {
                index++;
                if (index >= N.length()) {
                    cout << result;
                    exit(0);
                }
            }
        }
        result++;
    }
    return 0;
}