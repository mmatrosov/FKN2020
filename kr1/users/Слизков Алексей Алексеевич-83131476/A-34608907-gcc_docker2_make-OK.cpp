#include <iostream>
#include <string>
#include <string_view>

bool NextToken(std::string_view& sv, const char delimeter, std::string_view& token) {
    if (sv.length() == 0)
        return false;
    if (sv.find(delimeter) == std::string::npos) {
        token = sv;
        sv = sv.substr(sv.length());
        return true;
    }
    int pos = sv.find(delimeter);
    token = sv.substr(0, pos);
    sv = sv.substr(pos + 1);
    return true;
}
