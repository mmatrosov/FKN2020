#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
    int contests;
    std::cin >> contests;
    std::set<std::string> names;
    std::vector<std::map<std::string, int>> result(contests);
    for (int i = 0; i < contests; ++i) {
        int participants;
        std::cin >> participants;
        for (int j = 0; j < participants; ++j) {
            std::string name;
            std::cin >> name;
            int curResult;
            std::cin >> curResult;
            names.emplace(name);
            result[i][name] = curResult;
        }
    }
    for (const auto& name : names) {
        std::cout << name << "\t";
        for (int i = 0; i < contests; ++i)
            std::cout << result[i][name] << "\t";
        std::cout << "\n";
    }
}
