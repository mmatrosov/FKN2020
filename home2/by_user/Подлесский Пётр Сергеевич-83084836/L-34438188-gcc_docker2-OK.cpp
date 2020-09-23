#include <iostream>
#include <set>
#include <deque>

using namespace std;

int main() {
    size_t ar_sz, win_sz;
    cin >> ar_sz >> win_sz;
    multiset<int> window;
    deque<int> d_window;
    int num;
    for (size_t i = 0; i < win_sz; ++i) {
        cin >> num;
        d_window.push_back(num);
        window.insert(num);
    }
    for (size_t i = 0; i < ar_sz - win_sz + 1; ++i) {
        cout << *window.begin() << '\n';
        window.erase(window.find(d_window[0]));
        d_window.pop_front();
        cin >> num;
        window.insert(num);
        d_window.push_back(num);
    }
}