#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int get_number(std::string& info) {
    int space = info.find(' ');
    if (space == -1) {
        int number = stoi(info);
        info.clear();
        return number;
    }
    int number = stoi(info.substr(0, space));
    info.erase(0, std::min(space + 1, static_cast<int>(info.length())));
    return number;
}

char get_char(std::string& info) {
    char result = info[0];
    info.erase(0, std::min(2, static_cast<int>(info.length())));
    return result;
}

int main() {
    std::vector<int> number_problems;
    std::vector<char> letter_problems;
    for (int i = 1; i <= 20; i++) {
        number_problems.push_back(i);
        letter_problems.push_back('A' + static_cast<char>(i - 1));
    }
    std::string contest_information;
    while (getline(std::cin, contest_information)) {
        int contest_number = get_number(contest_information);
        int number_of_problems = get_number(contest_information);
        std::cout << contest_number << ' ';
        if (isalpha(contest_information[0])) {
            std::vector<char> char_problems;
            while (!contest_information.empty())
                char_problems.push_back(get_char(contest_information));
            std::vector<char> difference;
            std::set_difference(letter_problems.begin(), letter_problems.end(),
                char_problems.begin(), char_problems.end(),
                std::inserter(difference, difference.begin()));
            char max_problem = 'A' + static_cast<char>(number_of_problems - 1);
            for (const char problem : difference) {
                if (problem > max_problem)
                    break;
                std::cout << problem << ' ';
            }
        } else {
            std::vector<int> int_problems;
            while (!contest_information.empty())
                int_problems.push_back(get_number(contest_information));
            std::vector<int> difference;
            std::set_difference(number_problems.begin(), number_problems.end(),
                int_problems.begin(), int_problems.end(),
                std::inserter(difference, difference.begin()));
            for (const int problem : difference) {
                if (problem > number_of_problems)
                    break;
                std::cout << problem << ' ';
            }
        }
        std::cout << '\n';
    }
}