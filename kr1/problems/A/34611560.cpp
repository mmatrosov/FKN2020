#include <iostream>
#include <string>
#include <string_view>

bool NextToken(std::string_view &sv, char delimiter, std::string_view &token) {
    if (sv.empty())
        return 0;
    for (int i = 0; i < sv.length(); i++) {
        if (sv[i] == delimiter) {
            token = sv.substr(0, i);
            sv.remove_prefix(i + 1);
            return 1;
        }
    }
    token = sv.data();
    sv.remove_prefix(sv.length());
    return 1;
}