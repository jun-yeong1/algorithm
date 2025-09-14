#include <iostream>

using namespace std;

int main() {
    string N;
    cin >> N;
    int ten = 0;
    if (N.size() == 1) {
        cout << N << endl;
    } else {
        for (int i = 0; i < N.size()-1; i++) {
            if (N[i] >= N[i+1]) {
                ten += 10;
            }
            if (i+1 == N.size()) {
                if (N[i+1] !=  ) {
                    cout << N[i+1] + ten << endl;
                } else {
                    if (N[i+1])
                }
            }
        }

    }
    

    return 0;
}