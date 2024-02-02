#include <bits/stdc++.h>

using namespace std;
// n = ���ռ�, k = �����¼�
int n, k;
// ���� ����
string sets[15];
// ���� ���� ������, 50�ڸ� �� ������
int setMod[15], fitMod[50];
// �޸������̼�
long long cache[1>>15][100];

// �Է¹��� �� ��� ������ ��� -> setMod
void MOD() {
    for (int i = 0; i < n; i++) {
        setMod = stoi(sets[i]) % k; 
    }
}
// n! ���丮�� ���ϱ� �и�
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
        // ����� ������ ���
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
    // 0~50 �ڸ� �� ������ -> fitMOD
    fitMod[0] = 1 % 10;
    for (int i = 1; i <= 50; i++) {
        fitMod[i] = (fitMod[i-1] * 10) % k;
    }
    fill(&cache[0][0], &cache[1<<14][100], -1);
    cout << fac(n);
    MOD();
}