#include <string_view>

using namespace std;

bool NextToken(string_view &txt, char del, string_view &tok) {
    if (txt.empty()) {
        return false;
    }
    for (auto it = txt.begin(); it != txt.end(); ++it) {
        if ((*it) == del) {
            tok = txt.substr(0, it - txt.begin());
            txt = txt.substr(it - txt.begin() + 1);
            return true;
        }
    }
    tok = txt;
    txt = "";
    return true;
}
