#include <iostream>
#include <map>

using namespace std;

int main() {
    size_t sp_am;
    map<int, pair<int, int>> sportsmen;
    int cur, prev;
    int start = -1;
    cin >> sp_am;
    for (size_t i = 0; i < sp_am; ++i) {
        cin >> cur >> prev;
        if (start == -1) {
            start = cur;
            sportsmen[cur] = {-1, -1};
        } else if (sportsmen.find(prev) == sportsmen.end()) {
            sportsmen[cur] = {-1, start};
            start = cur;
        } else {
            sportsmen[cur] = {prev, sportsmen[prev].second};
            if (sportsmen[prev].second != -1) {
                sportsmen[sportsmen[prev].second].first = cur;
            }
            sportsmen[prev].second = cur;
        }
    }
    cur = start;
    while (cur != -1) {
        cout << cur << '\n';
        cur = sportsmen[cur].second;
    }
}