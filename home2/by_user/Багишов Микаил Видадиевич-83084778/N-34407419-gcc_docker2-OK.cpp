#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string contest_spec;
    while (std::getline(std::cin, contest_spec)) {
        std::istringstream iss(contest_spec);
        {
            int contest_id;
            iss >> contest_id;
            std::cout << contest_id;
        }
        int total_count;
        iss >> total_count;
        std::vector<int> all;
        for (int p = 0; p < total_count; ++p) {
            all.push_back(p);
        }
        std::vector<int> known;
        bool use_digits = true;
        {
            std::string k;
            while (iss >> k) {
                int problem_code;
                if (!isdigit(k[0])) {
                    use_digits = false;
                    problem_code = (k[0] - 'A');
                } else {
                    problem_code = std::stoi(k) - 1;
                }
                known.push_back(problem_code);
            }
        }
        std::vector<int> unknown;
        std::set_difference(all.begin(), all.end(), known.begin(), known.end(),
                            std::back_inserter(unknown));
        for (int const problem : unknown) {
            std::string k;
            if (use_digits) {
                k = std::to_string(problem + 1);
            } else {
                k = static_cast<char>(problem + 'A');
            }
            std::cout << ' ' << k;
        }
        std::cout << '\n';
    }
}