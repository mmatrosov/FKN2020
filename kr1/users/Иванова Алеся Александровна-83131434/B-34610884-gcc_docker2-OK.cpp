#include <iostream>
#include <vector>
#include <string>

signed main() {
    int cnt_files;
    std::cin >> cnt_files;
    std::vector<std::vector<std::string>> files(cnt_files);
    int max_sz = 0;
    for (int i = 0; i < cnt_files; ++i) {
        int sz_file;
        std::cin >> sz_file;
        if (sz_file > max_sz)
            max_sz = sz_file;
        files[i].resize(sz_file);
        for (int e = 0; e < sz_file; ++e) {
            std::cin >> files[i][e];
        }
    }
    for (int i = 0; i < max_sz; ++i) {
        for (const auto& file : files) {
            if (i < file.size())
                std::cout << file[i];
            std::cout << "\t";
        }
        std::cout << "\n";
    }
}
