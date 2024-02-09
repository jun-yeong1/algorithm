#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preOrder;

void postOrder(int pStart, int pEnd) {
    if (pStart >= pEnd) return;
    // ũ��
    int N = pEnd - pStart;
    // �ش� Ʈ�� root ���
    int root = preOrder[pStart];
    int L_i;
    for (int i = pStart; i < pEnd; i++) {
        if (preOrder[i] > root) {
            L_i = i;
            break;
        } else L_i = pEnd-1;
    }
    // left node size
    int L = L_i - pStart;
    postOrder(pStart+1, pStart+L);
    postOrder(pStart+L, pStart+N-1);
    // ���� ��ȸ ���
    cout << root << '\n';
}

int main(void) {
    int a;
    // �Է��� �޾����� true
    while (cin >> a) {
        preOrder.push_back(a);
    }
    postOrder(0, preOrder.size());
}