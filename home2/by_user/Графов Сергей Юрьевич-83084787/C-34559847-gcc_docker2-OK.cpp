#include<iostream>
#include<string>
#include<vector>

int main() {
    std::vector<std::string> words;
    std::string s;
    while (std::cin >> s) {
        words.push_back(s);
    }
    for (int c = 'a'; c <= 'z'; ++c) {
        bool t = true;
        for (auto& i : words) {
            if (i.find(c) == std::string::npos) {
                t = false;
            }
        }
        if (t) {
            std::cout << char(c);
        }
    }
}
