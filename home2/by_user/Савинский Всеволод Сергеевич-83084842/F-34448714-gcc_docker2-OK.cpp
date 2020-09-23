#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>

struct Student {
    std::string name, surname;
    std::vector<std::string> uni_list;
    int d, m, y, grade;
};

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> uni_lim;
    std::map<std::string, std::vector<Student>> uni_students;
    for (size_t i = 0; i < n; ++i) {
        std::string name;
        int limit;
        std::cin >> name >> limit;
        uni_lim[name] = limit;
        uni_students[name];
    }

    int m;
    std::cin >> m;
    std::vector<Student> students(m);
    for (auto &st : students) {
        int uni_list_size;
        std::cin >> st.name >> st.surname >> st.d >> st.m >> st.y
            >> st.grade >> uni_list_size;
        st.uni_list.resize(uni_list_size);
        for (auto &uni : st.uni_list) {
            std::cin >> uni;
        }
    }

    sort(students.begin(), students.end(),
    [](const auto &s1, const auto &s2) {
        return std::tie(s2.grade, s1.y, s1.m, s1.d, s1.surname, s1.name)
             < std::tie(s1.grade, s2.y, s2.m, s2.d, s2.surname, s2.name);
    });

    for (const auto &st : students) {
        for (const auto &uni : st.uni_list) {
            if (uni_lim[uni]) {
                uni_lim[uni] -= 1;
                uni_students[uni].emplace_back(st);
                break;
            }
        }
    }

    for (auto &[uni_name, students_list] : uni_students) {
        std::cout << uni_name << '\t';
        sort(students_list.begin(), students_list.end(), [](const auto &s1, const auto &s2) {
           return std::tie(s1.surname, s1.name, s1.y, s1.m, s1.d) <
                  std::tie(s2.surname, s2.name, s2.y, s2.m, s2.d);
        });
        for (const auto &st : students_list) {
            std::cout << st.name << ' ' << st.surname << '\t';
        }
        std::cout << std::endl;
    }
}
