#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    map<int, set<string>> pages;
    set<int> nums;
    size_t word_am;
    string word;
    int page;
    cin >> word_am;
    for (size_t i = 0; i < word_am; ++i) {
        cin >> word >> page;
        nums.insert(page);
        pages[page].insert(word);
    }
    for (auto p : nums) {
        cout << p;
        for (auto w : pages[p])
            cout << ' ' << w;
        cout << '\n';
    }
}