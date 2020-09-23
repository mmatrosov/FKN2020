#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> types = {
    "bfpv",
    "cgjkqsxz",
    "dt",
    "l",
    "mn",
    "r"
};

int main() {
    string s;
    cin >> s;
    string s1;
    s1.push_back(s[0]);
    for (size_t i = 1; i < s.size(); i++) {
        for (size_t t = 0; t < 6; t++) {
            if (types[t].find(s[i]) != string::npos) {
                s1.push_back('0' + t + 1);
                break;
            }
        }
    }
    string s2;
    s2.push_back(s1[0]);
    for (size_t i = 1; i < s1.size(); i++) {
        if (s1[i] != s2.back()) {
            s2.push_back(s1[i]);
        }
    }
    while (s2.size() > 4) {
        s2.pop_back();
    }
    while (s2.size() < 4) {
        s2.push_back('0');
    }
    cout << s2 << endl;
    return 0;
}
