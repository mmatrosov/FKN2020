#include <iostream>
#include <string>

int main() {
    std::string s;
    getline(std::cin, s);
    int i = 0, ans = 0;
    for (; i < s.length(); ++ans) {
        int byte = s[i];
        if (!(byte >> 7))
            ++i;
        else if (!((byte >> 5) % 2))
            i += 2;
        else if (!((byte >> 4) % 2))
            i += 3;
        else
            i += 4;
    }
    std::cout << ans;
    return 0;
}