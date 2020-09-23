#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct student {
    std::string name;
    std::string surname;
    int date;
    int month;
    int year;
    student() {}
    bool operator == (const student& stud) const {
        return (name == stud.name && surname == stud.surname && date == stud.date
            && month == stud.month && year == stud.year);
    }
};

bool age_comparator(const student& st1, const student& st2);

bool name_comparator(const student& st1, const student& st2) {
    if (st1 == st2)
        return false;
    if (st1.surname != st2.surname)
        return (st1.surname < st2.surname);
    if (st1.name != st2.surname)
        return (st1.name < st2.surname);
    return age_comparator(st1, st2);
}

bool age_comparator(const student& st1, const student& st2) {
    if (st1 == st2)
        return false;
    if (st1.year != st2.year)
        return (st1.year < st2.year);
    if (st1.month != st2.month)
        return (st1.month < st2.month);
    if (st1.date != st2.date)
        return (st1.date < st2.date);
    return name_comparator(st1, st2);
}

int main() {
    int numOfStudents;
    std::cin >> numOfStudents;
    std::vector<student> studentList(numOfStudents);
    for (student& currentStudent : studentList) {
        std::cin >> currentStudent.name >> currentStudent.surname;
        std::cin >> currentStudent.date >> currentStudent.month >> currentStudent.year;
    }
    std::string typeOfSorting;
    std::cin >> typeOfSorting;
    if (typeOfSorting == "date") {
        sort(studentList.begin(), studentList.end(), age_comparator);
    } else {
        sort(studentList.begin(), studentList.end(), name_comparator);
    }
    for (const student& currentStudent : studentList) {
        std::cout << currentStudent.name << ' ' << currentStudent.surname << ' ';
        std::cout << currentStudent.date << '.' << currentStudent.month << '.';
        std::cout << currentStudent.year << '\n';
    }
}
