#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

struct student{
    std::string name, surname;
    std::vector<int> date;
    int score;
    std::vector<std::string> univ;

    student(std::string name, std::string surname, std::vector<int> date,
        int score = 0, std::vector<std::string> univ = {}):
        name(name), surname(surname), date(date), score(score), univ(univ) {}

    bool operator<(const student& other) const {
        return std::tie(score, other.date, other.surname, other.name) <
            std::tie(other.score, date, surname, name);
    }
};

bool cmp(const student& stud1, const student& stud2) {
    return std::tie(stud1.surname, stud1.name, stud1.date) <
        std::tie(stud2.surname, stud2.name, stud2.date);
}

signed main() {
    int n;
    std::cin >> n;
    std::map<std::string, int> places;
    std::map<std::string, std::vector<student>> students_in_university;
    for (int i = 0; i < n; i++) {
        std::string university;
        int cnt;
        std::cin >> university >> cnt;
        places[university] = cnt;
        students_in_university[university];
    }
    int m;
    std::cin >> m;
    std::vector<student> students;
    for (int i = 0; i < m; i++) {
        std::string name, surname;
        int day, month, year, score;
        std::cin >> name >> surname >> day >> month >> year >> score;
        std::vector<int> date = {year, month, day};
        int cnt;
        std::cin >> cnt;
        std::vector<std::string> univ(cnt);
        for (int e = 0; e < cnt; e++)
            std::cin >> univ[e];
        students.emplace_back(name, surname, date, score, univ);
    }
    std::sort(students.begin(), students.end());
    std::reverse(students.begin(), students.end());
    for (const auto& stud : students) {
        for (const auto& univ : stud.univ) {
            if (places[univ]) {
                --places[univ];
                students_in_university[univ].emplace_back(stud);
                break;
            }
        }
    }
    for (auto& univ : students_in_university) {
        std::cout << univ.first << "\t";
        std::sort(univ.second.begin(), univ.second.end(), cmp);
        for (const auto& stud1 : univ.second) {
            std::cout << stud1.name << " " << stud1.surname << "\t";
        }
        std::cout << "\n";
    }
}
