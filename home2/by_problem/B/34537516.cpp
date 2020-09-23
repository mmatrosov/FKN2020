#include <iostream>
#include <unordered_set>

struct string_set {
    std::unordered_set<std::string> dict;

    void addString(std::string query) {
        dict.insert(query);
    }

    void delString(std::string query) {
        dict.erase(query);
    }

    bool findString(std::string query) {
        return dict.find(query) != dict.end();
    }
};

int main() {
    string_set mainSet;
    char type;
    while (std::cin >> type, type != '#') {
        std::string query;
        std::cin >> query;
        if (type == '+')
            mainSet.addString(query);
        if (type == '-')
            mainSet.delString(query);
        if (type == '?')
            std::cout << (mainSet.findString(query) ? "YES" : "NO") << '\n';
    }
    return 0;
}