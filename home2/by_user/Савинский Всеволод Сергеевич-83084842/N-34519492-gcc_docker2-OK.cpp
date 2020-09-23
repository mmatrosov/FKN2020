#include <algorithm>
#include <iterator>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

int main() {
    std::vector<int> digits(24), letters(24);
    std::iota(digits.begin(), digits.end(), 1);
    std::iota(letters.begin(), letters.end(), 'A');

    std::string contest;
    while (getline(std::cin, contest)) {
        std::stringstream stream(contest);
        int contest_num, cnt;
        stream >> contest_num >> cnt;
        std::cout << contest_num << ' ';
        if (isdigit(contest.back())) {
            std::set_difference(digits.begin(), digits.begin() + cnt,
                                std::istream_iterator<int>(stream), std::istream_iterator<int>(),
                                std::ostream_iterator<int>(std::cout, " "));
        } else {
            std::set_difference(letters.begin(), letters.begin() + cnt,
                                std::istream_iterator<char>(stream), std::istream_iterator<char>(),
                                std::ostream_iterator<char>(std::cout, " "));
        }
        std::cout << std::endl;
    }
}
