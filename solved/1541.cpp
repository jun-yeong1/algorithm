#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string m;
    cin >> m;
    string number;
    vector<int> num;
    vector<char> op;
    for (int i = 0; i < m.length(); i++) {
        if (m[i] != '+' && m[i] != '-') {
            number += m[i];
        } else {
            int n = stoi(number);
            num.push_back(n);
            number.clear();
            op.push_back(m[i]);
        }
    }
    int n = stoi(number);
    num.push_back(n);
    int result = n;
    for (int i = 0; i < op.size(); i++) {
        // - 일 경우 뒷 부호 모두 -
        if (op[i] == '-') {
            for (int j = i; j < op.size(); j++) {
                op[j] = '-';
            }
            break;
        }
    }
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == '+') {
            result = num[i] + num[i+1];
            num[i+1] = result;
        } else {
            result = num[i] - num[i+1];
            num[i+1] = result;
        }
    }
    
    cout << result;
}