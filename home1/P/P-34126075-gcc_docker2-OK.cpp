#include <iostream>
#include <vector>
#include <algorithm>

struct student {
    std::string name, surname;
    int birth_day, birth_month, birth_year;

    student(std::string name = "", std::string surname = "",
        int birth_day = 0, int birth_month = 0, int birth_year = 0):
        name(name), surname(surname),
        birth_day(birth_day), birth_month(birth_month), birth_year(birth_year) {}
};

bool sort_comp_name(const student& student1, const student& student2) {
    if (student1.surname != student2.surname)
        return student1.surname < student2.surname;
    if (student1.name != student2.name)
        return student1.name < student2.name;

    if (student1.birth_year != student2.birth_year)
        return student1.birth_year < student2.birth_year;
    if (student1.birth_month != student2.birth_month)
        return student1.birth_month < student2.birth_month;
    return student1.birth_day < student2.birth_day;
}

bool sort_comp_date(const student& student1, const student& student2) {
    if (student1.birth_year != student2.birth_year)
        return student1.birth_year < student2.birth_year;
    if (student1.birth_month != student2.birth_month)
        return student1.birth_month < student2.birth_month;
    if (student1.birth_day != student2.birth_day)
        return student1.birth_day < student2.birth_day;

    if (student1.surname != student2.surname)
        return student1.surname < student2.surname;
    return student1.name < student2.name;
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
    if (way_of_sorting == "name")
        sort(students.begin(), students.end(), sort_comp_name);
    else
        sort(students.begin(), students.end(), sort_comp_date);
    for (const auto& stud : students)
        std::cout << stud.name << " " << stud.surname << " " <<
        stud.birth_day << "." << stud.birth_month << "." << stud.birth_year << "\n";
}
