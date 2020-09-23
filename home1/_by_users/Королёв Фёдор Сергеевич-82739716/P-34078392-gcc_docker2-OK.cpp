#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Student {
    std::string name, surname;
    int d, m, y;
    Student(std::string &_name, std::string &_surname, int _d, int _m, int _y) {
        name = _name;
        surname = _surname;
        d = _d;
        m = _m;
        y = _y;
    }
};

bool comp_name(Student &s1, Student &s2) {
    if (s1.surname != s2.surname) {
        return s1.surname < s2.surname;
    }
    if (s1.name != s2.name) {
        return s1.name < s2.name;
    }
    if (s1.y != s2.y) {
        return s1.y < s2.y;
    }
    if (s1.m != s2.m) {
        return s1.m < s2.m;
    }
    return s1.d < s2.d;
}

bool comp_date(Student &s1, Student &s2) {
    if (s1.y != s2.y) {
        return s1.y < s2.y;
    }
    if (s1.m != s2.m) {
        return s1.m < s2.m;
    }
    if (s1.d != s2.d) {
        return s1.d < s2.d;
    }
    if (s1.surname != s2.surname) {
        return s1.surname < s2.surname;
    }
    return s1.name < s2.name;
}

int main() {
    int n;
    std::cin >> n;
    std::vector <Student> st;
    for (int i = 0; i < n; i++) {
        std::string name, surname;
        int d, m, y;
        std::cin >> name >> surname >> d >> m >> y;
        st.push_back(Student(name, surname, d, m, y));
    }
    std::string type;
    std::cin >> type;
    if (type == "name") {
        std::sort(st.begin(), st.end(), comp_name);
    } else {
        std::sort(st.begin(), st.end(), comp_date);
    }
    for (int i = 0; i < n; i++) {
        std::cout << st[i].name << ' ' << st[i].surname << ' ' << st[i].d << '.';
        std::cout << st[i].m << '.' << st[i].y << '\n';
    }
    return 0;
}