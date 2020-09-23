#include <iostream>
#include <vector>
#include <string>

int main() {
    size_t files_am, file_cop, max_len = 0;
    std::cin >> files_am;
    std::vector<std::vector<std::string>> ans(files_am);
    for (size_t i = 0; i < files_am; ++i) {
        std::cin >> file_cop;
        max_len = std::max(max_len, file_cop);
        std::vector<std::string> cur_file(file_cop);
        for (size_t j = 0; j < file_cop; ++j)
            std::cin >> cur_file[j];
        ans[i] = cur_file;
    }
    for (size_t i = 0; i < max_len; ++i) {
        for (auto vec : ans) {
            if (vec.size() > i)
                std::cout << vec[i];
            std::cout << '\t';
        }
        std::cout << '\n';
    }
}