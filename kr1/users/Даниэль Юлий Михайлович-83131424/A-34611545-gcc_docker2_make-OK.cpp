#include <string_view>

bool NextToken(std::string_view& sv, char delimiter, std::string_view& token) {
    int i = 0;
    for (; i < sv.size() && sv[i] != delimiter; ++i) {
        continue;
    }
    token = sv.substr(0, i);
    if (token.empty()) return false;
    if (i < sv.size()) {
        sv = sv.substr(i + 1, sv.size() - i);
    } else {
        sv = sv.substr(sv.size() - 1, 0);
    }
    return true;
}
