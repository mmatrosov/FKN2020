#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int word_count(std::string s) {
    enum state {space, word} State(space);
    int count = 0;
    for (char c : s) {
        if (State == space ^ (c == ' ' || c == '\t' || c == '\n')) {
            if (State == space)
                count++;
            State = State == space ? word : space;
        }
    }
    return count;
}

int main() {
    std::string keys;
    getline(std::cin, keys);
    std::vector<std::string> v;
    std::string s;
    while (getline(std::cin, s))
        v.push_back(s);
    if (keys.find("-l") != std::string::npos)
        std::cout << v.size() << ' ';
    if (keys.find("-w") != std::string::npos) {
        std::cout << std::accumulate(v.begin(), v.end(), 0, [](int a, std::string s) {
            return a + word_count(s);
        }) << ' ';
    }
    if (keys.find("-m") != std::string::npos) {
        std::cout << std::accumulate(v.begin(), v.end(), 0, [](int a, std::string s) {
            return a + s.length() + 1;
        }) << ' ';
    }
    if (keys.find("-L") != std::string::npos) {
        std::cout << (*std::max_element(v.begin(), v.end(), [](std::string s, std::string t) {
            return s.length() < t.length();
        })).length() << ' ';
    }
    return 0;
}
