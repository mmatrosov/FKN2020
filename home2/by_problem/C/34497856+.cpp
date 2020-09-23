#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    auto chars = std::set<char>(s.begin(), s.end());
    std::string commonChars(chars.begin(), chars.end());
    while (std::cin >> s) {
        std::string tempCommonChars(commonChars);
        commonChars = "";
        std::set<char> ourChars(s.begin(), s.end());
        std::set_intersection(ourChars.begin(), ourChars.end(), tempCommonChars.begin(),
            tempCommonChars.end(), std::back_inserter(commonChars));
    }
    std::cout << commonChars;
    return 0;
}
