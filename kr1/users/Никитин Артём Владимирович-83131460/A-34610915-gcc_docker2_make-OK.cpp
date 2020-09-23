#include <string_view>

using namespace std;

bool NextToken(string_view& sv, const char delimiter, string_view& token) {
    if (sv.empty())
        return false;
    int pos = sv.find(delimiter);
    if (pos == -1)
        pos = sv.length();
    token = sv.substr(0, pos);
    if (pos == sv.length())
        sv = "";
    else
        sv = sv.substr(pos + 1, sv.length());
    return true;
}