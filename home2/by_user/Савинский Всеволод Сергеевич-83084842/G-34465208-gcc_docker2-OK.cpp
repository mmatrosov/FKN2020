#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <set>
#include <map>

int main() {
    std::map<int, std::set<std::string>> page_words;

    size_t n;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::string word;
        int num;
        std::cin >> word >> num;
        page_words[num].insert(word);
    }

    for (const auto &[page_num, words] : page_words) {
        std::cout << page_num << ' ';
        std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;
    }
}
