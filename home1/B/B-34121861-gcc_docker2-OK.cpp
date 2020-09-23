#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<char, char> char_to_group() {
        vector<string> groups = {
                "aehiouwy",
                "bfpv",
                "cgjkqsxz",
                "dt",
                "l",
                "mn",
                "r"
        };
        map<char, char> result;
        for (int i = 0; i < groups.size(); ++i) {
                for (const auto &ch : groups[i]) {
                        result[ch] = '0' + i;
                }
        }
        return result;
}

int main() {
        auto to_grp = char_to_group();

        string word, answer;
        cin >> word;

        answer += word[0];
        word.erase(word.begin());

        for (const char &ch : word) {
                if (answer.size() == 4) {
                        break;
                }
                if (to_grp[ch] == '0' || answer.back() == to_grp[ch]) {
                        continue;
                }
                answer += to_grp[ch];
        }
        while (answer.size() != 4) {
                answer += "0";
        }
        cout << answer << endl;
}

