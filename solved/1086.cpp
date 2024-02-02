#include <bits/stdc++.h>

using namespace std;
// n = 집합수, k = 나누는수
int n, k;
// 집합 원소
string sets[15];
// 집합 원소 나머지, 50자리 수 나머지
int setMod[15], fitMod[50];
// 메모이제이션
long long cache[1>>15][100];

// 입력받은 수 모두 나머지 계산 -> setMod
void MOD() {
    for (int i = 0; i < n; i++) {
        setMod = stoi(sets[i]) % k; 
    }
}
// n! 팩토리얼 구하기 분모
long long fac(int num) {
    long long result = 1;
    for (int i = 0; i < num; i++) {
        result *= num - i;  
    }
    return result;
}
long long sung(int bit, int re) {
    if (bit == (1<<n)-1) return ;
    long long& ret = cache[bit][re];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; i++) {
        // 사용한 숫자인 경우
        if(bit & (1<<i)) continue;
    }
    return ret;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cache[i];
    }
    cin >> k;
    // 0~50 자리 수 나머지 -> fitMOD
    fitMod[0] = 1 % 10;
    for (int i = 1; i <= 50; i++) {
        fitMod[i] = (fitMod[i-1] * 10) % k;
    }
    fill(&cache[0][0], &cache[1<<14][100], -1);
    cout << fac(n);
    MOD();
}