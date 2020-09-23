#include <iostream>
#include <string>
#include <vector>

int main() {
    int m;
    std::cin >> m;
    std::vector<std::vector<std::string>> files(m);
    int mxn = 0;
    for (int n_file = 0; n_file < m; ++n_file) {
        int n;
        std::cin >> n;
        mxn = std::max(n, mxn);
        for (int n_line = 0; n_line < n; ++n_line) {
            std::string line;
            std::cin >> line;
            files[n_file].push_back(line);
        }
    }
    for (int n_file = 0; n_file < m; ++n_file)
        files[n_file].resize(mxn);

    for (int n_line = 0; n_line < mxn; ++n_line) {
        for (int n_file = 0; n_file < m; ++n_file) {
            std::cout << files[n_file][n_line] << '\t';
        }
        std::cout << std::endl;
    }
    return 0;
}