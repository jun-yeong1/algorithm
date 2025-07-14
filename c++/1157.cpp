#include <iostream>
#include <string>

using namespace std;

int main () {
    string word;
    cin >> word;

    int alphabet[26] = {0};

    for (char c : word) {
        c = toupper(c);
        alphabet[c - 'A']++;
    }
    int max_count = 0;
    char result = '?';
    bool duplicate = false; // 중복 토글

    for (int i = 0; i < 26; i++) {
        if (max_count < alphabet[i]) {
            max_count = alphabet[i];
            result = i + 'A';
            duplicate = false;
        } else if (max_count == alphabet[i]) {
            duplicate = true;
        }
    }
    if (duplicate) cout << "?" << endl;
    else cout << result << endl;
    return 0;
}