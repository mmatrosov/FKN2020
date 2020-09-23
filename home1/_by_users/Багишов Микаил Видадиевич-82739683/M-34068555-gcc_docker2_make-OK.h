#include <string>
#include <vector>
std::string join(std::vector<std::string> const &tokens, char const delimeter) {
    bool is_first_token = true;
    std::string joint;
    for (std::string const &token : tokens) {
        if (is_first_token) {
            is_first_token = false;
        } else {
            joint.push_back(delimeter);
        }
        joint += token;
    }
    return joint;
}