#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

struct Student {
    std::string name, surname;
    int day, month, year;
};

bool sortByDate(const Student& a, const Student& b) {
    return std::tie(a.year, a.month, a.day, a.surname, a.name) <
        std::tie(b.year, b.month, b.day, b.surname, b.name);
}

bool sortByName(const Student& a, const Student& b) {
    return std::tie(a.surname, a.name, a.year, a.month, a.day) <
        std::tie(b.surname, b.name, b.year, b.month, b.day);
}

int main() {
    int studentsCount;
    std::cin >> studentsCount;
    std::vector<Student> students(studentsCount);
    for (int i = 0; i < studentsCount; ++i) {
        std::string curName, curSurname;
        int curDay, curMonth, curYear;
        std::cin >> curName >> curSurname >> curDay >> curMonth >> curYear;
        students[i] = {curName, curSurname, curDay, curMonth, curYear};
    }

    std::string flag;
    std::cin >> flag;
    bool isSortByDate = flag == "date" ? true : false;
    sort(students.begin(), students.end(), isSortByDate ? sortByDate : sortByName);

    for (const auto& elem : students) {
        std::cout << elem.name << ' ' << elem.surname << ' ' <<
            elem.day << '.' << elem.month << '.' << elem.year << '\n';
    }
}
