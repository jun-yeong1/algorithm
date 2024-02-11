#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preOrder;

void postOrder(int pStart, int pEnd) {
    if (pStart >= pEnd) return;
    // 크기
    int N = pEnd - pStart;
    // 해당 트리 root 노드
    int root = preOrder[pStart];
    int L_i;
    for (int i = pStart; i < pEnd; i++) {
        if (preOrder[i] > root) {
            L_i = i;
            break;
        } else if (i == pEnd-1) {
            L_i = pEnd;
            break;
        }
    }
    // left node size
    int L = L_i - pStart;
    postOrder(pStart+1, pStart+L);
    postOrder(pStart+L, pStart+N);
    // 후위 순회 출력
    cout << root << '\n';
}

int main(void) {
    int a;
    // 입력을 받았으면 true
    while (cin >> a) {
        preOrder.push_back(a);
    }
    postOrder(0, preOrder.size());
}