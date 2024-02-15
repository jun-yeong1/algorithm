#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool compare(int a, int b) {
    if (abs(a) < abs(b)) {
        return false;
    } else if (abs(a) == abs(b)) {
        return a > b;
    } else {
        return true;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> heap;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            if (heap.empty()) {
                cout << 0 << '\n';
            } else {
                cout << heap.front() << '\n';
                pop_heap(heap.begin(), heap.end(), compare);
                heap.pop_back();
            }
        } else {
            heap.push_back(a);
            push_heap(heap.begin(), heap.end(), compare);
        }
    }
}