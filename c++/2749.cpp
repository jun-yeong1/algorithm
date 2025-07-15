#include <iostream>
#include <vector>
#define DEV 1000000
using namespace std;

int main () {
    long long int num;
    cin >> num;
    int pis = 15 * (DEV/10); // 피사노 주기
    vector<int> fib(pis);
    fib[0] = 0; fib[1] = 1;    
    for (int i = 2; i < pis; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % DEV;
    }
    cout << fib[num % pis] << endl;

    return 0;
}
// 벡터를 사용해야 메모리 충분함 즉 동적으로 해야 메모리 넘치지 않음
// 피사노 주기란 피보나치 수를 어떤 수 m로 나눌 때, 나머지는 항상 주기를 가지게 됨
// 주기의 길이를 p라고 하면 n번째 피보나치 수를 m으로 나눈 나머지는
// n % p번 째 피보나치 수를 m으로 나눈 나머지와 같다
// 주기는 m = 10^k (k>2) 일 때, 항상 15*10^(k-1) 이다
// 문제에서 m 을 1,000,000(10^6)로 정의하므로 주기는 15*10^5 