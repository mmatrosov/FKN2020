#include <iostream>
#include <numeric>

std::string join(const std::vector<std::string>& tokens, char delimeter) {
    if (!tokens.size())
        return "";
    return std::accumulate(std::next(tokens.begin()), tokens.end(), tokens[0],
        [delimeter](std::string a, std::string b) {return a + delimeter + b;});
}
