#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
  std::map<char, int> freq;

  std::string elem;
  int count_words = 0;
  while (std::cin >> elem) {
    ++count_words;
    std::set<char> letters(elem.begin(), elem.end());
    for (char c : letters) ++freq[c];  //
  }
  for (auto [key, num] : freq) {
    if (num == count_words) std::cout << key;
  }
  std::cout << std::endl;
  return 0;
}