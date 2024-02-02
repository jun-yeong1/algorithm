#include <bits/stdc++.h>

using namespace std;
// n = ���ռ�, k = �����¼�
int n, k;
// ���� ����
string sets[15];
// ���� ���� ������, 50�ڸ� �� ������
int setMod[15], s_len[15], fitMod[50];
// �޸������̼�
long long cache[1>>15][100];

// �Է¹��� �� ��� ������ ��� -> setMod
// �Է¹��� �� ��� ���� ���� -> s_len
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
// ���
long long sung(int bit, int re) {
    if (bit == (1<<n)-1) return (re % k == 0);
    long long& ret = cache[bit][re];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; i++) {
        // ����� ������ ���
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
    // 0~50 �ڸ� �� ������ -> fitMOD
    fitMod[0] = 1 % k;
    for (int i = 1; i <= 50; i++) {
        fitMod[i] = (fitMod[i-1] * 10) % k;
    }
    memset(&cache, -1, sizeof(cache));
    MOD();
    long long p = sung(0, 0), q = 1;
    // sung ����� 0�� ��� �Ұ���
    //if (p == 0) cout << "0/1"; return 0;
    // �и� ���丮�� n!
    for (int i = 1; i <= n; i++) q *= i;
    // algorithm in numeric ���� �Լ� �ִ����� ��ȯ
    long long gcd_n = gcd(p, q);
    cout << p << "/" << q << " ";
    p /= gcd_n; q /= gcd_n;
    cout << p << "/" << q;
}