#include <deque>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::string surname;
    std::string where_to_put;
    std::deque<std::string> pile;
    std::cin >> n;
    while (n--) {
        std::cin >> surname >> where_to_put;
        if (where_to_put == "top")
            pile.push_front(surname);
        else
            pile.push_back(surname);
    }
    int m;
    std::cin >> m;
    while (m--) {
        int position;
        std::cin >> position;
        std::cout << pile[position - 1] << '\n';
    }
}
