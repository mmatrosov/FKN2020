#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split_words(const string& s) {
    stringstream ss;
    ss << s;
    vector<string> words;
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

vector<string> split_lines(const string& s) {
    stringstream ss;
    ss << s;
    vector<string> lines;
    string line;
    while (getline(ss, line)) {
        lines.push_back(line);
    }
    return lines;
}

int cnt_chars(const string& s) {
    return s.size();
}

int cnt_lines(const string& s) {
    return split_lines(s).size();
}

int cnt_words(const string& s) {
    return split_words(s).size();
}

size_t len_max_line(const string& s) {
    auto lines = split_lines(s);
    size_t max_len = 0;
    for (const string& line : lines) {
        max_len = max(max_len, line.size());
    }
    return max_len;
}

int main() {
    string first;
    getline(cin, first);
    auto flags = split_words(first);
    stringstream ss;
    ss << cin.rdbuf();
    string content = ss.str();
    if (find(flags.begin(), flags.end(), "-l") != flags.end()) {
        cout << cnt_lines(content) << ' ';
    }
    if (find(flags.begin(), flags.end(), "-w") != flags.end()) {
        cout << cnt_words(content) << ' ';
    }
    if (find(flags.begin(), flags.end(), "-m") != flags.end()) {
        cout << cnt_chars(content) << ' ';
    }
    if (find(flags.begin(), flags.end(), "-L") != flags.end()) {
        cout << len_max_line(content) << ' ';
    }
    cout << endl;
    return 0;
}
