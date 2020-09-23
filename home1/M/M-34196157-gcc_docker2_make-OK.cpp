#include <string>
#include <vector>

std::string join(const std::vector<std::string>& tokens, char delimiter) {
        std::string res;
        for (size_t ind = 0; ind < tokens.size(); ++ind) {
                res += tokens[ind];
                if (ind + 1 < tokens.size()) {
                       res += delimiter;
                }
        }
        return res;
}
