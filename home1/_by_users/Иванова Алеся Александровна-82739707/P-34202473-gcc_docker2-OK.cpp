#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

struct student {
    std::string name, surname;
    int birth_day, birth_month, birth_year;
};

bool sort_comp_name(const student& student1, const student& student2) {
    return std::tie(student1.surname, student1.name, student1.birth_year, student1.birth_month,
        student1.birth_day) < std::tie(student2.surname, student2.name, student2.birth_year,
        student2.birth_month, student2.birth_day);
}

bool sort_comp_date(const student& student1, const student& student2) {
    return std::tie(student1.birth_year, student1.birth_month, student1.birth_day,
        student1.surname, student1.name) < std::tie(student2.birth_year, student2.birth_month,
        student2.birth_day, student2.surname, student2.name);
}

signed main() {
    int number_of_students;
    std::cin >> number_of_students;
    std::vector<student> students(number_of_students);
    for (int i = 0; i < number_of_students; ++i) {
        std::cin >> students[i].name >> students[i].surname >>
        students[i].birth_day >> students[i].birth_month >> students[i].birth_year;
    }
    std::string way_of_sorting;
    std::cin >> way_of_sorting;
    sort(students.begin(), students.end(),
         (way_of_sorting == "name" ? sort_comp_name : sort_comp_date));
    for (const auto& stud : students)
        std::cout << stud.name << " " << stud.surname << " " <<
        stud.birth_day << "." << stud.birth_month << "." << stud.birth_year << "\n";
}
