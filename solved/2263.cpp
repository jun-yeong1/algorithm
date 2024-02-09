#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inorder, postorder;

void printPreOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if(inStart >= inEnd || postStart >= postEnd) return;
    // 현재 벡터 크기
    const int N = inEnd - inStart;
    // 루트 노드는 후위순회의 마지막
    const int root = postorder[postEnd-1];
    // 왼쪽 서브트리는 중위순회의 처음에서 루트노드까지
    // L-i == L 위치
    int L_i;
    for (int i = inStart; i < inEnd; i++) {
        if (inorder[i] == root) {
            L_i = i;
            break;
        }
    }
    // L = L의 크기
    int L = L_i - inStart;
    // 먼저 루트 노드 출력
    cout << root << " ";
    // 중위 후위 둘 다 0번부터 L까지 
    printPreOrder(inStart, inStart+L, postStart, postStart+L);
    // 후위의 마지막은 루트노드이기에 N-1까지 슬라이싱
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