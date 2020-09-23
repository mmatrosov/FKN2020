#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>

struct Student {
    std::string firstName, lastName;
    int score, day, month, year;
    std::vector<std::string> preference;
};

bool sort_by_name(const Student& a, const Student& b) {
    return std::tie(a.lastName, a.firstName, a.year, a.month, a.day)
        < std::tie(b.lastName, b.firstName, b.year, b.month, b.day);
}

bool sort_by_score(const Student& a, const Student& b) {
    return std::tie(b.score, a.year, a.month, a.day, a.lastName, a.firstName)
        < std::tie(a.score, b.year, b.month, b.day, b.lastName, b.firstName);
}

int main() {
    int universities;
    std::cin >> universities;
    std::vector<std::string> university(universities);
    std::map<std::string, int> restCount;
    for (int i = 0; i < universities; ++i) {
        std::cin >> university[i];
        int rest;
        std::cin >> rest;
        restCount[university[i]] = rest;
    }
    int students;
    std::cin >> students;
    std::vector<Student> student(students);
    for (int i = 0; i < students; ++i) {
        std::string firstName, lastName;
        int day, month, year, score;
        std::cin >> firstName >> lastName >> day >> month >> year >> score;
        student[i] = {firstName, lastName, score, day, month, year, {}};
        int cntPreferences;
        std::cin >> cntPreferences;
        for (int j = 0; j < cntPreferences; ++j) {
            std::string pref;
            std::cin >> pref;
            student[i].preference.emplace_back(pref);
        }
    }
    std::map<std::string, std::vector<Student>> enrolle;
    sort(student.begin(), student.end(), sort_by_score);
    for (const auto& st : student) {
        for (const auto& pref : st.preference) {
            if (restCount[pref] > 0) {
                enrolle[pref].push_back(st);
                --restCount[pref];
                break;
            }
        }
    }
    sort(university.begin(), university.end());
    for (const auto& name : university) {
        std::cout << name << "\t";
        auto& ref = enrolle[name];
        sort(ref.begin(), ref.end(), sort_by_name);
        for (const auto& student : enrolle[name])
            std::cout << student.firstName << " " << student.lastName << "\t";
        std::cout << "\n";
    }
}
