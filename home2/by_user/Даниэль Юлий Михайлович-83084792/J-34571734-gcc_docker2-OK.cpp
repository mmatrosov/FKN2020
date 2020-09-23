#include <deque>
#include <iostream>
#include <string>

int main() {
    std::deque<std::string> students;
    int n_studs;
    std::cin >> n_studs;
    for (int i = 0; i < n_studs; ++i) {
        std::string name, where;
        std::cin >> name >> where;
        if (where == "top")
            students.push_front(name);
        else
            students.push_back(name);
    }
    int n_queries;
    std::cin >> n_queries;
    for (int i = 0; i < n_queries; ++i) {
        int ind;
        std::cin >> ind;
        std::cout << students[--ind] << std::endl;
    }
    return 0;
}