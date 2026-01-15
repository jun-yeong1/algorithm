#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 1000001
int n;
// arr 입력, L 수열, count_L 각 위치에서 수열 크기
int arr[MAX];
vector<int> L, count_L, result;

int main() {
    int cur_num, count = 0; // 수열의 끝 인덱스와 크기 저장(출력용)
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (L.size() == 0) {
            L.push_back(arr[i]);
            count_L.push_back(1);
        } else if (L[L.size()-1] < arr[i]) {
            L.push_back(arr[i]);
            count_L.push_back(L.size());
        } else {
            // 이진탐색 구현으로도 가능
            // 자신보다 크거나 같은 수의 iterator 포인트 반환
            // 배열 (arr, arr+갯수, 목표), 벡터 (arr.begin(), arr.end(), 목표)
            int index = lower_bound(L.begin(), L.end(), arr[i]) - L.begin();
            L[index] = arr[i];
            //= *(lower_bound(L.begin(), L.end(), num[i])) = num[i];
            count_L.push_back(index+1);
        }
        if (count_L[i] > count) {
            count = count_L[i];
            cur_num = i;
        }
    }
    printf("%d\n", count);
    result.push_back(arr[cur_num]);
    for (int i = cur_num-1; i >= 0; i--) {
        if (count_L[i] == count_L[cur_num]-1 && arr[i] < arr[cur_num]) {
            result.push_back(arr[i]);
            cur_num = i;
        }
    }

    for (int i = result.size()-1; i >= 0; i--) {
        printf("%d ", result.at(i));
    }
    return 0;
}