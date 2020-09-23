#include <iostream>
#include <string>
#include <map>

std::string first_change(std::string s) {
    std::string final;
    final.push_back(s[0]);
    std::map<char, int> decode;
    decode['b'] = 1;
    decode['f'] = 1;
    decode['p'] = 1;
    decode['v'] = 1;
    decode['c'] = 2;
    decode['g'] = 2;
    decode['j'] = 2;
    decode['k'] = 2;
    decode['q'] = 2;
    decode['s'] = 2;
    decode['x'] = 2;
    decode['z'] = 2;
    decode['d'] = 3;
    decode['t'] = 3;
    decode['l'] = 4;
    decode['m'] = 5;
    decode['n'] = 5;
    decode['r'] = 6;
    int last_index = 0;
    for (int i = 1; i < s.size(); i++) {
        char now = decode[s[i]] + '0';
        if (final[last_index] != now && now != '0') {
            final.push_back(now);
            last_index += 1;
        }
    }
    return final;
}

int main() {
    std::string word;
    std::cin >> word;
    std::string final;
    final = first_change(word);
    final += "0000";
    int cnt = 0;
    for (const char &i : final) {
        std::cout << i;
        cnt++;
        if (cnt == 4) {
            break;
        }
    }

    return 0;
}
