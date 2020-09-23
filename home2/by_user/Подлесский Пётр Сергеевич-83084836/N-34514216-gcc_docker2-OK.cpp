#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void print_diff(string &data, const vector<T> &all_elems, size_t prob_am) {
    vector<T> elems;
    vector<T> diff;
    istringstream iss(data);
    T elem;
    while (iss >> elem) {
        elems.push_back(elem);
    }
    set_difference(all_elems.begin(), all_elems.begin() + prob_am,
    elems.begin(), elems.end(), inserter(diff, diff.begin()));
    for (auto e : diff) cout << ' ' << e;
}

int main() {
    vector<int> numbs(20);
    vector<char> letters(26);
    string s_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 1; i <= 20; ++i)
        numbs[i - 1] = i;
    for (int i = 0; i < 26; ++i)
        letters[i] = (i + 'A');
    int contest_n;
    size_t prob_am;
    string data;
    while (cin >> contest_n) {
        cin >> prob_am;
        getline(cin, data);
        cout << contest_n;
        if (data.find_first_of(s_letters) != string::npos) {
            print_diff(data, letters, prob_am);
        } else {
            print_diff(data, numbs, prob_am);
        }
        cout << '\n';
    }
}