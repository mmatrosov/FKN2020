#include <iostream>
#include <string_view>

bool NextToken(std::string_view& text, char delimiter, std::string_view& token) {
    size_t size = text.size(), ind = 0;
    while (ind < size && text[ind] == delimiter) {
        ++ind;
    }
    if (ind == size) {
        return false;
    }
    size_t startPos = ind, len = 0;
    while (ind < size && text[ind] != delimiter) {
        ++ind;
        ++len;
    }
    token = text.substr(startPos, len);
    text.remove_prefix(ind);
    return true;
}
