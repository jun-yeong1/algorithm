#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inorder, postorder;

void printPreOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if(inStart >= inEnd || postStart >= postEnd) return;
    // ���� ���� ũ��
    const int N = inEnd - inStart;
    // ��Ʈ ���� ������ȸ�� ������
    const int root = postorder[postEnd-1];
    // ���� ����Ʈ���� ������ȸ�� ó������ ��Ʈ������
    // L-i == L ��ġ
    int L_i;
    for (int i = inStart; i < inEnd; i++) {
        if (inorder[i] == root) {
            L_i = i;
            break;
        }
    }
    // L = L�� ũ��
    int L = L_i - inStart;
    // ���� ��Ʈ ��� ���
    cout << root << " ";
    // ���� ���� �� �� 0������ L���� 
    printPreOrder(inStart, inStart+L, postStart, postStart+L);
    // ������ �������� ��Ʈ����̱⿡ N-1���� �����̽�
    printPreOrder(inStart+L+1, inStart+N, postStart+L, postStart+N-1);
}
int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        inorder.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        postorder.push_back(b);
    }
    printPreOrder(0, n, 0, n);
}