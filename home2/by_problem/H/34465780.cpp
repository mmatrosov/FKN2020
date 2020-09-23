#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <set>

int main() {
    size_t n;
    std::cin >> n;

    std::map<std::string, std::vector<int>> student_grades;
    for (size_t i = 0; i < n; ++i) {
        size_t k;
        std::cin >> k;
        for (size_t j = 0; j < k; ++j) {
            std::string name;
            int res;
            std::cin >> name >> res;
            if (student_grades[name].empty()) {
                student_grades[name].resize(n);
            }
            student_grades[name][i] = res;
        }
    }

    for (const auto &[name, grades] : student_grades) {
        std::cout << name << '\t';
        std::copy(grades.begin(), grades.end(), std::ostream_iterator<int>(std::cout, "\t"));
        std::cout << std::endl;
    }
}
