#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

struct Student {
        std::string name, surname;
        int d, m, y;
};

bool compare_by_date(const Student &fir, const Student &sec) {
       return std::tie(fir.y, fir.m, fir.d, fir.surname, fir.name)
               < std::tie(sec.y, sec.m, sec.d, sec.surname, sec.name);
}

bool compare_by_name(const Student &fir, const Student &sec) {
        return std::tie(fir.surname, fir.name, fir.y, fir.m, fir.d)
                < std::tie(sec.surname, sec.name, sec.y, sec.m, sec.d);
}

int main() {
        int n;
        std::cin >> n;
        std::vector<Student> students;
        for (size_t i = 0; i < n; ++i) {
                std::string name, surname;
                int d, m, y;
                std::cin >> name >> surname >> d >> m >> y;
                students.push_back({name, surname, d, m, y});
        }

        std::string sort_type;
        std::cin >> sort_type;

        std::sort(students.begin(), students.end(),
                        sort_type == "date" ? compare_by_date : compare_by_name);

        for (const auto &[name, surname, d, m, y] : students) {
                std::cout << name << ' ' << surname <<
                        ' ' << d << '.' << m << '.' << y << std::endl;
        }
}

