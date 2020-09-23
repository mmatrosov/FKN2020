#include <iostream>
#include <string>

using namespace std;

pair<size_t, size_t> FindVowels(const string& text, size_t pos) {
    const string vowels = "aeiouyAEIOUY";
    size_t left = text.find_first_of(vowels, pos);
    size_t right = text.find_first_not_of(vowels, left);
    if (left == string::npos) {
        return {left, 0};
    }
    if (right == string::npos) {
        return {left, text.size() - left};
    }
    return {left, right - left};
}

// int main() {
//     string text;
//     getline(cin, text);
//     size_t pos = 0;
//     while (true) {
//         auto [start, length] = FindVowels(text, pos);
//         if (start == string::npos)
//             break;
//         cout << start << " " << length << " " << text.substr(start, length) << "\n";
//         pos = start + length;
//     }
// }
