#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> heap;

void push_heap(int newValue) {
    heap.push_back(newValue);
    int idx = heap.size() - 1;
    while (idx > 0 && heap[(idx-1)/2] < heap[idx]) {
        swap(heap[idx], heap[(idx-1)/2]);
        idx = (idx-1) / 2;
    }
}
void pop_heap() {
    if (heap.empty()) {
        cout << 0 << '\n';
        return;
    }
    cout << heap[0] << '\n';
    heap[0] = heap.back();
    heap.pop_back();
    int here = 0;
    while (true) {
        int left = here * 2 + 1;
        int right = here * 2 + 2;
        if (left >= heap.size()) break;
        int next = here;
        if (heap[next] < heap[left]) {
            next = left;
        }
        if (right < heap.size() && heap[next] < heap[right]) {
            next = right;
        }
        if (next == here) break;
        swap(heap[here], heap[next]);
        here = next;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            pop_heap();
        } else push_heap(a);
    }
}  