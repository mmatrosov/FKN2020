#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
  int words;
  std::cin >> words;
  std::map<int, std::set<std::string>> keyWords;
  for (int i = 0; i < words; ++i) {
    std::string word;
    std::cin >> word;
    int page;
    std::cin >> page;
    keyWords[page].emplace(word);
  }
  size_t curSize = 0;
  for (auto& [key, values] : keyWords) {
    size_t curPos = 0;
    std::cout << key << " ";  //
    for (const auto& word : values) {
      std::cout << word;
      if (curPos + 1 != values.size()) std::cout << " ";
      ++curPos;
    }
    if (curSize + 1 != keyWords.size()) std::cout << "\n";
    ++curSize;
  }
}
