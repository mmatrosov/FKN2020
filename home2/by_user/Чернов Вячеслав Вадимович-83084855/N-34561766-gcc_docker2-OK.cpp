#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parse(const std::string& text) {
    std::vector<std::string> result;
    size_t ind = 0, length = text.size();
    while (ind < length) {
        std::string word;
        while (ind < length && text[ind] != ' ') {
            word += text[ind];
            ++ind;
        }
        result.emplace_back(word);
        ++ind;
    }
    return result;
}

int string_to_int(const std::string& number) {
    int result = 0;
    for (char c : number)
        result = result * 10 + c - '0';
    return result;
}

int main() {
    std::string text;
    while (getline(std::cin, text)) {
        auto word = parse(text);
        int tasks = string_to_int(word[1]);
        std::cout << word[0] << " ";
        if (word.size() < 3 || isdigit(word[2][0])) {
            std::vector<int> allTasks, solvedTasks;
            for (int i = 0; i < tasks; ++i)
                allTasks.emplace_back(i + 1);
            for (size_t i = 2; i < word.size(); ++i)
                solvedTasks.emplace_back(string_to_int(word[i]));
            std::vector<int> unsolvedTasks(tasks - solvedTasks.size());
            std::set_difference(allTasks.begin(), allTasks.end(),
                solvedTasks.begin(), solvedTasks.end(), unsolvedTasks.begin());
            for (int x : unsolvedTasks)
                std::cout << x << " ";
        } else {
            std::vector<char> allTasks, solvedTasks;
            for (int i = 0; i < tasks; ++i)
                allTasks.emplace_back(i + 'A');
            for (size_t i = 2; i < word.size(); ++i)
                solvedTasks.emplace_back(word[i][0]);
            std::vector<char> unsolvedTasks(tasks - solvedTasks.size());
            std::set_difference(allTasks.begin(), allTasks.end(),
                solvedTasks.begin(), solvedTasks.end(), unsolvedTasks.begin());
            for (char x : unsolvedTasks)
                std::cout << x << " ";
        }
        std::cout << "\n";
    }
}
