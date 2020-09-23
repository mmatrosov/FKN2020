#include <iostream>
#include <map>
#include <string>

std::map<char, char> keys = {{'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
                       {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'},
                       {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
                       {'d', '3'}, {'t', '3'},
                       {'l', '4'},
                       {'m', '5'}, {'n', '5'},
                       {'r', '6'}};

int main() {
    std::string s;
    std::cin >> s;
    std::string t = "";
    t += s[0];
    for (int i = 1; i < s.length(); i++) {
        if (keys.find(s[i]) == keys.end())
            continue;
        if (keys[s[i]] == t.back())
            continue;
        t += keys[s[i]];
    }
    if (t.length() >= 4) {
        std::cout << t.substr(0, 4);
        return 0;
    }
    std::cout << t;
    for (int i = t.length(); i < 4; i++)
        std::cout << '0';
    return 0;
}