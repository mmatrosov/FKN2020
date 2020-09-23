#include <deque>
#include <iostream>
#include <string>

int main() {
    int students;
    std::cin >> students;
    std::deque<std::string> stack;
    for (int i = 0; i < students; ++i) {
        std::string name, type;
        std::cin >> name >> type;
        if (type == "top")
            stack.push_front(name);
        else
            stack.push_back(name);
    }
    int queries;
    std::cin >> queries;
    for (int i = 0; i < queries; ++i) {
        int position;
        std::cin >> position;
        std::cout << stack[position - 1] << "\n";
    }
}
