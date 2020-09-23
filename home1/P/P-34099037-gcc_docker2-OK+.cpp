#include <iostream>
#include <vector>
#include <algorithm>

struct student {
    std::string firstName, lastName;
    int day, month, year;
    student(){}
};

std::istream &operator>> (std::istream &in, student &stud) {
    in >> stud.firstName >> stud.lastName >> stud.day >> stud.month >> stud.year;
    return in;
}

std::ostream &operator<< (std::ostream &out, student &stud) {
    out << stud.firstName << ' ' << stud.lastName << ' ';
    out << stud.day << '.' << stud.month << '.' << stud.year;
    return out;
}

bool cmp_name(const student &stud1, const student &stud2) {
    if (stud1.lastName + stud1.firstName == stud2.lastName + stud2.firstName) {
        if (stud1.year == stud2.year) {
            if (stud1.month == stud2.month) {
                return stud1.day < stud2.day;
            } else {
                return stud1.month < stud2.month;
            }
        } else {
            return stud1.year < stud2.year;
        }
    } else {
        return stud1.lastName + stud1.firstName < stud2.lastName + stud2.firstName;
    }
}

bool cmp_date(const student &stud1, const student &stud2) {
    if (stud1.year == stud2.year) {
        if (stud1.month == stud2.month) {
            if (stud1.day == stud2.day) {
                return stud1.lastName + stud1.firstName < stud2.lastName + stud2.firstName;
            } else {
                return stud1.day < stud2.day;
            }
        } else {
            return stud1.month < stud2.month;
        }
    } else {
            return stud1.year < stud2.year;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<student> students(n);
    for (student &stud : students) std::cin >> stud;
    std::string type;
    std::cin >> type;
    if (type == "name") {
        std::sort(students.begin(), students.end(), cmp_name);
    } else {
        std::sort(students.begin(), students.end(), cmp_date);
    }
    for (student &stud : students) {
        std::cout << stud << std::endl;
    }
    return 0;
}