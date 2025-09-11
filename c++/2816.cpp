#include <iostream>
#include <string>

using namespace std;

int main() {
    int N = 0;
    cin >> N;

    int arr[N];
    int kbs1, kbs2 = 0; // 각 채널 위치
    for (int i = 0; i < N; i++) {
        string channel = ""; cin >> channel;
        if (channel == "KBS1") {
            arr[i] = 1;
            kbs1 = i;
        } else if (channel == "KBS2") {
            arr[i] = 2;
            kbs2 = i;
        } else {
            arr[i] = 0;
        }
    }

    int curser = 0; // 현재 화살표 위치;
    while(1) {
        for (int i = 0; i < kbs1; i++) {
            printf("1");
            curser++;
        }
        for (int i = 0; i < kbs1; i++) {
            printf("4");
            curser--;
            if (kbs2 == curser) {
                kbs2++; // 1채널 변경으로 인해 2채널 변경될 경우
            }
        }
        for (int i = 0; i < kbs2; i++) {
            printf("1");
            curser++;
        }
        for (int i = 0; i < kbs2-1; i++) {
            printf("4");
        }
        break;
    }
    return 0;
}