#include <iostream>
#include <string>
#include <set>


int main() {
    std::string s, ans = "";
    std::cin >> s;
    ans += s[0];
    std::set <char> badLet;
    badLet.insert('a');
    badLet.insert('e');
    badLet.insert('h');
    badLet.insert('i');
    badLet.insert('o');
    badLet.insert('u');
    badLet.insert('w');
    badLet.insert('y');
    for (int i = 1; i < s.size(); i += 1) {
        if (badLet.find(s[i]) == badLet.end()) {
            ans += s[i];
        }
    }
    for (int i = 1; i < ans.size(); i += 1) {
        if (ans[i] == 'b' || ans[i] == 'f' || ans[i] == 'p' || ans[i] == 'v') {
            ans[i] = '1';
        } else if (ans[i] == 'd' || ans[i] == 't') {
            ans[i] = '3';
        } else if (ans[i] == 'l') {
            ans[i] = '4';
        } else if (ans[i] == 'm' || ans[i] == 'n') {
            ans[i] = '5';
        } else if (ans[i] == 'r') {
            ans[i] = '6';
        } else {
            ans[i] = '2';
        }
    }
    int printed = 1;
    char lastC = ans[0];
    std::cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) {
        if (printed == 4) {
            break;
        }
        if (ans[i] == lastC) {
            continue;
        }
        printed += 1;
        lastC = ans[i];
        std::cout << ans[i];
    }
    while (printed < 4) {
        std::cout << 0;
        printed += 1;
    }
    return 0;
}