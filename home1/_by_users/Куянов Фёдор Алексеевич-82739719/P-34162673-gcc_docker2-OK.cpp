#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct student {
    string first_name, last_name;
    int day, month, year;
};

bool cmp_name(const student& a, const student& b) {
    return tie(a.last_name, a.first_name, a.year, a.month, a.day) <
           tie(b.last_name, b.first_name, b.year, b.month, b.day);
}

bool cmp_date(const student& a, const student& b) {
    return tie(a.year, a.month, a.day, a.last_name, a.first_name) <
           tie(b.year, b.month, b.day, b.last_name, b.first_name);
}

int main() {
    size_t n;
    cin >> n;
    vector<student> students(n);
    for (size_t i = 0; i < n; i++) {
        cin >> students[i].first_name >> students[i].last_name;
        cin >> students[i].day >> students[i].month >> students[i].year;
    }
    string tp;
    cin >> tp;
    if (tp == "date")
        sort(students.begin(), students.end(), cmp_date);
    else if (tp == "name")
        sort(students.begin(), students.end(), cmp_name);
    for (const student& cur : students) {
        cout << cur.first_name << ' ' << cur.last_name << ' ';
        cout << cur.day << '.' << cur.month << '.' << cur.year << '\n';
    }
}
