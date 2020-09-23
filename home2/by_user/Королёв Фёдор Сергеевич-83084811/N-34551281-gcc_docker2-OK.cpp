#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cctype>
#include <iterator>
#include <algorithm>

using namespace std;

int str_to_int(std::string s) {
    int ans = 0, st = 1;
    for (int i = 0; i < s.size(); ++i) {
        ans += st * (s[s.size() - i - 1] - '0');
        st *= 10;
    }
    return ans;
}

int main() {
    std::string contest;
    while (getline(std::cin, contest)) {
        contest += ' ';
        int id = contest.find(' ');
        int num = str_to_int(contest.substr(0, id));
        ++id;
        int tasks = str_to_int(contest.substr(id, contest.find(' ', id) - id));
        id = contest.find(' ', id) + 1;
        int digs = 0, lets = 0;
        for (int i = id; i < contest.size(); ++i) {
            if (isdigit(contest[i])) {
                digs = 1;
                break;
            } else if (isupper(contest[i])) {
                lets = 1;
                break;
            }
        }
        if (lets) {
            std::string at = "", ot = "";  // at means all tasks, ot means our tasks
            for (int i = 0; i < tasks; ++i) {
                at += 'A' + i;
            }
            for (int i = id; i < contest.size(); ++i) {
                if (isupper(contest[i])) {
                    ot += contest[i];
                }
            }
            std::string ans = "";
            set_difference(at.begin(), at.end(), ot.begin(), ot.end(), inserter(ans, ans.begin()));
            std::cout << num << ' ';
            for (auto el : ans) {
                std::cout << el << ' ';
            }
            std::cout << '\n';
            continue;
        }
        std::vector <int> at, ot;
        for (int i = 0; i < tasks; ++i) {
                at.push_back(i + 1);
        }
        for (int i = id; i < contest.size(); ++i) {
            if (isdigit(contest[i])) {
                int val;
                if (i + 1 < contest.size() && isdigit(contest[i + 1])) {
                    val = str_to_int(contest.substr(i, 2));
                } else {
                    val = contest[i] - '0';
                }
                ot.push_back(val);
            }
        }
        std::vector <int> ans;
        set_difference(at.begin(), at.end(), ot.begin(), ot.end(), inserter(ans, ans.begin()));
        std::cout << num << ' ';
        for (auto el : ans) {
            std::cout << el << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}