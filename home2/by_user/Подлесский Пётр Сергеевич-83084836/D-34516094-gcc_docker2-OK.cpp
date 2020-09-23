#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    set<vector<string>> ans;
    vector<string> cur_vec;
    string cur_str;
    bool include_root = false;
    size_t sz;
    while (getline(cin, line)) {
        cur_str = "";
        cur_vec.clear();
        for (size_t i = 1; i < line.size(); ++i) {
            if (line[i] != '/') {
                cur_str += line[i];
            } else {
                cur_vec.push_back(cur_str);
                cur_str = "";
            }
        }
        if (cur_vec.size() != 0)
            include_root = true;
        sz = cur_vec.size();
        for (size_t j = 0; j < sz; ++j) {
            ans.insert(cur_vec);
            cur_vec.pop_back();
        }
    }
    if (include_root)
        cout << "/\n";
    for (auto ve : ans) {
        cout << "/";
        for (auto s : ve) {
            cout << s << '/';
        }
        cout << '\n';
    }
}