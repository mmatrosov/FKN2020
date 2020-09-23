#include <iostream>
#include <vector>

template<typename T, typename U>
auto max(T a, U b) {
    return a > b ? a : b;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::string>> contents(n);
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            std::string token;
            std::cin >> token;
            contents[i].push_back(token);
        }
    }
    int lines = 0;
    for (const std::vector<std::string>& file : contents) {
        lines = max(lines, file.size());
    }
    for (int line_id = 0; line_id < lines; ++line_id) {
        for (int file_id = 0; file_id < n; ++file_id) {
            std::cout << (line_id < contents[file_id].size() ? contents[file_id][line_id] : "")
                            << "\t";
        }
        std::cout << "\n";
    }
    return 0;
}
