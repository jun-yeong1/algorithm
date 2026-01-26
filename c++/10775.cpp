#include <iostream>
#include <vector>

using namespace std;
int gate[100001];
vector<int> plane;
// 부모 찾기
int find(int num) {
    // gate 빈자리 있으면
    if (gate[num] == num) {
        return num;
    }
    // gate 빈자리없으면 해당 gate 부모 찾아서 리턴
    return gate[num] = find(gate[num]);
}
void join(int a, int b) {
    int parent_a = find(a);
    int parent_b = find(b);
    // 부모가 같지 않다면
    if (parent_a != parent_b) {
        // a 부모를 작은 b 부모로 변경
        gate[parent_a] = parent_b;
    }
}

int main() {
    int G, P;
    int result = 0;
    cin >> G;
    cin >> P;
    for (int i = 0; i <= G; i++) {
        gate[i] = i; // 트리
    }
    for (int i = 0; i < P; i++) {
        int num;
        cin >> num;
        plane.push_back(num);
    }

    for (int num : plane) {
        // 부모 없으면
        if (find(num) == 0) break;
        else {
            result++;
            join(find(num), find(num)-1);
        }
    }
    cout << result;
    
    return 0;
}