#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct student{
    std::string name;
    std::string surname;
    int date;
    int month;
    int year;
};

bool cmp_date(student, student);
bool cmp_name(student, student);


bool cmp_date(student a, student b) {
    if (a.year == b.year) {
        if (a.month == b.month) {
            if (a.date == b.date) {
                return cmp_name(a, b);
            }
            return a.date < b.date;
        }
        return a.month < b.month;
    }
    return a.year < b.year;
}

bool cmp_name(student a, student b) {
    if (a.surname == b.surname) {
        if (a.name == b.name) {
            return cmp_date(a, b);
        }
        return a.name < b.name;
    }
    return a.surname < b.surname;
}

void print(const student &a) {
    std::cout << a.name << " " << a.surname << " ";
    std::cout << a.date << "." << a.month << "." << a.year << "\n";
}

int main() {
    int n;
    std::cin >> n;
    std::vector<student> students(n);
    for (int i = 0; i < n; i += 1) {
        student now;
        std::cin >> now.name >> now.surname;
        std::cin >> now.date >> now.month >> now.year;
        students[i] = now;
    }
    std::string type;
    std::cin >> type;
    if (type == "name") {
        sort(students.begin(), students.end(), cmp_name);
    } else {
        sort(students.begin(), students.end(), cmp_date);
    }
    for (const auto &i : students) {
        print(i);
    }



    return 0;
}
