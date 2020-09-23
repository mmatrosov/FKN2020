#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int contest_num;
    std::cin >> contest_num;
    std::map<std::string, std::vector<int>> points;
    for (int i = 0; i < contest_num; ++i) {
        int stud_num;
        std::cin >> stud_num;
        for (int j = 0; j < stud_num; ++j) {
            std::string name;
            int grade;
            std::cin >> name >> grade;
            if (points[name].size() < contest_num) points[name].resize(contest_num);
            points[name][i] = grade;
        }
    }
    for (auto &[name, grades] : points) {
        std::cout << name;
        for (int grade : grades) std::cout << '\t' << grade;
        std::cout << std::endl;
    }
    return 0;
}