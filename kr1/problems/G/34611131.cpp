#include <iostream>
#include <string>
#include <map>
#include <vector>

std::map<std::string, int> final_standings(std::vector<std::map<std::string, int>>& by_contests) {
    std::map<std::string, int> final;
    for (const std::map<std::string, int>& contest_results : by_contests) {
        for (const std::pair<std::string, int>& score : contest_results) {
            const std::string& student = score.first;
            int his_result = score.second;
            if (final.find(student) == final.end())
                final[student] = std::numeric_limits<int>::min();
            final[student] = std::max(final[student], his_result);
        }
    }
    return final;
}

/*int main() {
    int n;
    std::cin >> n;
    std::vector<std::map<std::string, int>> by_contests(n);
    for (int contest_id = 0; contest_id < n; ++contest_id) {
        int m;
        std::cin >> m;
        for (int i = 0; i < m; ++i) {
            std::string student;
            int result;
            std::cin >> student >> result;
            by_contests[contest_id][student] = result;
        }
    }
    std::map<std::string, int> final(final_standings(by_contests));
    for (const std::pair<std::string, int>& result : final) {
        std::cout << "student " << result.first << " got " << result.second << std::endl;
    }
    return 0;
}

3

2
petrov 4
ivanov -3

2
ivanov -7
sidorov 0

1
petrov 28

*/
