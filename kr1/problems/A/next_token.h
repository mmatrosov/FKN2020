#include <string_view>

bool NextToken(std::string_view& sv, char delim, std::string_view& tok) {
    if (sv.empty())
        return false;
    auto pos = sv.find(delim);
    if (pos != sv.npos) {
        tok = sv.substr(0, pos);
        sv = sv.substr(pos + 1);
    } else {
        tok = sv;
        sv = "";
    }
    return true;
}

