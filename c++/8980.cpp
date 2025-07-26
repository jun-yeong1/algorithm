#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int truck[2001]; // 마을별 박스 수
vector<pair<pair<int, int>, int>> arr;
// 오름차순 정렬
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.second == b.first.second) return a.first.first < b.first.first;
    else return a.first.second < b.first.second;
}
int main() {
    int N, C;
    cin >> N >> C;
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int in, out, num = 0;
        cin >> in >> out >> num;
        arr.push_back({{in, out}, num});
    }
    sort(arr.begin(), arr.end(), compare);
    int result = 0; // 마을에 내릴 박스 총 개수
    // i = 현재 위치의 마을
    for (int i = 0; i < arr.size(); i++) {
        int start = arr[i].first.first;
        int end = arr[i].first.second;
        int bsize = arr[i].second;
        int max_truck = 0;

        for (int j = start; j < end; j++) {
            max_truck = max(truck[j], max_truck);
        }

        int box = min(bsize, C-max_truck); // 남은 공간 수(최소)
        
        for (int k = start; k < end; k++) {
            truck[k] += box;
        }
        result += box;
    }
    cout << result << endl;
    
    return 0;
}
// 먼저 현재 위치의 마을에 내려야할 물건을 내린 뒤
// 이 마을에서 보낼 물건을 싣는다
// 배열 초기화를 해야함