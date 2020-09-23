#include <vector>
#include <string>
#include <iostream>


int main() {
    std::string temp;
    size_t cnt_files;
    std::cin >> cnt_files;
    std::vector<std::vector<std::string>> files(cnt_files);
    for (auto &file_data : files) {
        size_t cnt_lines;
        std::cin >> cnt_lines;
        std::getline(std::cin, temp);
        file_data.reserve(cnt_lines);
        std::string line;
        for (size_t _i = 0; _i < cnt_lines; ++_i) {
            std::getline(std::cin, line);
            file_data.push_back(line);
        }
    }
    std::size_t max_len = 0;
    for (auto const &file_data : files) {
        max_len = std::max(max_len, file_data.size());
    }
    for (size_t row = 0; row < max_len; ++row) {
        bool is_first = true;
        for (auto const &file_data : files) {
            if (is_first) {
                is_first = false;
            } else {
                std::cout << '\t';
            }
            if (file_data.size() <= row) {
                continue;
            }
            std::cout << file_data[row];
        }
        std::cout << '\n';
    }
}