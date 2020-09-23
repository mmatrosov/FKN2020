#include <string>
#include <utility>

using namespace std;

pair <size_t, int> FindVowels(string text, int pos) {
    string vowels = "aeiouyAEIOUY";
    while (pos < text.size() && vowels.find(text[pos]) == string::npos) {
        pos += 1;
    }
    if (pos == text.size()) {
        return {string::npos, 0};
    }
    pair <size_t, int> ans;
    ans.first = pos;
    ans.second = 0;
    while (pos < text.size() && vowels.find(text[pos]) != string::npos) {
        ans.second++;
        pos++;
    }
    return ans;
}
