#include <string_view>
#include <string>

bool NextToken(std::string_view& string, char delimiter, std::string_view& out) {
    if (string.empty()) {
        return false;
    }
    auto const pos = string.find(delimiter);
    if (pos == std::string::npos) {
        out = string;
        string = string.substr(0, 0);
        return true;
    }
    out = string.substr(0, pos);
    string = string.substr(pos+1);
    return true;
}