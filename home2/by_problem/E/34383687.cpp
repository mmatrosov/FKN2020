#include <iostream>
#include <map>
#include <string>

struct student{
    long long sum_of_marks = 0;
    long long cnt = 0;
};

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, student> students;
    for (int i = 0; i < n; i++) {
        std::string name;
        std::cin >> name;
        long long mark;
        std::cin >> mark;
        students[name].sum_of_marks += mark;
        students[name].cnt += 1;
        std::cout << students[name].sum_of_marks / students[name].cnt << "\n";
    }


    return 0;
}
