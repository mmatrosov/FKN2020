#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_bits(int x) {
    string ans;
    while (x > 0) {
        ans.push_back('0' + x % 2);
        x >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    vector<int> ans;
    int future = 0;
    int current = 0;
    for (unsigned char x : s) {
        if (x < (1 << 7)) {
            ans.push_back(x);
        } else if (!(x & (1 << 6))) {
            x &= (1 << 6) - 1;
            current = (current << 6) | x;
            if (--future == 0) {
                ans.push_back(current);
            }
        } else {
            string bits = to_bits(x);
            int pos0 = bits.find('0');
            future = pos0 - 1;
            x &= (1 << (7 - pos0)) - 1;
            current = x;
        }
    }
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
