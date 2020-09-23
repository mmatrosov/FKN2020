#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<size_t> lens = {7, 11, 16, 21};

const vector<vector<string> > models = {
    {"0xxxxxxx"},
    {"110xxxxx", "10xxxxxx"},
    {"1110xxxx", "10xxxxxx", "10xxxxxx"},
    {"11110xxx", "10xxxxxx", "10xxxxxx", "10xxxxxx"}
};

string to_bits(int x) {
    string ans;
    while (x > 0) {
        ans.push_back('0' + x % 2);
        x >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int to_int(string s) {
    int x = 0;
    for (size_t i = 0; i < s.size(); i++) {
        x = x * 2 + (s[i] - '0');
    }
    return x;
}

int main() {
    string ans;
    int x;
    while (cin >> x) {
        string bits = to_bits(x);
        size_t final_len_ind = lower_bound(lens.begin(), lens.end(), bits.size()) - lens.begin();
        size_t final_len = lens[final_len_ind];
        reverse(bits.begin(), bits.end());
        while (bits.size() < final_len) {
            bits.push_back('0');
        }
        reverse(bits.begin(), bits.end());
        int pos = 0;
        for (const string& elem : models[final_len_ind]) {
            string cur = elem;
            for (size_t i = 0; i < cur.size(); i++) {
                if (cur[i] == 'x') {
                    cur[i] = bits[pos++];
                }
            }
            ans.push_back(to_int(cur));
        }
    }
    cout << ans << endl;
    return 0;
}
