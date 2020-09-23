#include <iostream>
#include <vector>
#include <string>

std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string ans;
    for (const std::string& elem : tokens) {
        ans += elem;
        ans.push_back(delimiter);
    }
    ans.pop_back();
    return ans;
}

// int main() {
//     size_t n;
//     std::cin >> n;
//     std::vector<std::string> tokens(n);
//     for (size_t i = 0; i < n; i++) {
//         std::cin >> tokens[i];
//     }
//     char delimiter;
//     std::cin >> delimiter;
//     std::cout << join(tokens, delimiter) << std::endl;
//     return 0;
// }
