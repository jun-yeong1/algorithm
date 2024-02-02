#include <bits/stdc++.h>

using namespace std;
// n = 집합수, k = 나누는수
int n, k;
// 집합 원소
string sets[15];
// 집합 원소 나머지, 50자리 수 나머지
int setMod[15], s_len[15], fitMod[50];
// 메모이제이션
long long cache[1>>15][100];

// 입력받은 수 모두 나머지 계산 -> setMod
// 입력받은 수 모두 길이 저장 -> s_len
void MOD() {
    for (int i = 0; i < n; i++) {
        s_len[i] = sets[i].size();
        int t = 0;
        for (auto c : sets[i]) {
            t *= 10; t % k;
            t += c - '0'; t %= k;
        }
        setMod[i] = t;
    }
}
// 계산
long long sung(int bit, int re) {
    if (bit == (1<<n)-1) return (re % k == 0);
    long long& ret = cache[bit][re];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; i++) {
        // 사용한 숫자인 경우
        if(bit & (1<<i)) continue;
        // ((i+1)%k)*(10^leni%k)+(i%k)
        int next = re * fitMod[s_len[i]] + setMod[i];
        ret += sung(bit | (1<<i), next % k);
    }
    return ret;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sets[i];
    }
    cin >> k;
    // 0~50 자리 수 나머지 -> fitMOD
    fitMod[0] = 1 % k;
    for (int i = 1; i <= 50; i++) {
        fitMod[i] = (fitMod[i-1] * 10) % k;
    }
    memset(&cache, -1, sizeof(cache));
    MOD();
    long long p = sung(0, 0), q = 1;
    // sung 결과가 0인 경우 불가능
    //if (p == 0) cout << "0/1"; return 0;
    // 분모 팩토리얼 n!
    for (int i = 1; i <= n; i++) q *= i;
    // algorithm in numeric 내장 함수 최대공약수 반환
    long long gcd_n = gcd(p, q);
    cout << p << "/" << q << " ";
    p /= gcd_n; q /= gcd_n;
    cout << p << "/" << q;
}