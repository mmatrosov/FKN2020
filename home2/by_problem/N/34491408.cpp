#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string s;
    std::vector<int> nums(20);
    std::vector<char> letters(20);
    for (int i = 1; i <= 20; ++i) {
        nums[i - 1] = i;
        letters[i - 1] = 'A' + i - 1;
    }

    while (std::getline(std::cin, s)) {
        std::stringstream x;
        x << s;
        std::string a;
        int i = 0;
        int quan = 0;
        std::vector<int> now;
        std::vector<char> now1;
        int type = 1;
        while (x >> a) {
            if (i == 0) {
                std::cout << a << " ";
            } else if (i == 1) {
                quan = std::stoi(a);
            } else {
                char letter = a[0];
                if (!std::isdigit(letter)) {
                    type = 0;
                }
                if (type == 0) {
                    now1.push_back(letter);
                } else {
                    now.push_back(std::stoi(a));
                }
            }
            i += 1;
        }
        std::vector<int> diff_nums;
        std::vector<char> diff_let;
        if (type == 1) {
            std::set_difference(nums.begin(), nums.begin() + quan,
                                now.begin(), now.end(),
                                std::inserter(diff_nums, diff_nums.begin()));
            for (auto& el : diff_nums) {
                std::cout << el << " ";
            }
        } else {
            std::set_difference(letters.begin(), letters.begin() + quan,
                                now1.begin(), now1.end(),
                                std::inserter(diff_let, diff_let.begin()));
            for (auto& el : diff_let) {
                std::cout << el << " ";
            }
        }
        std::cout << "\n";
    }


    return 0;
}
