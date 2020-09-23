#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<std::string> strings;
  char t;
  std::string elem;
  while (std::cin >> t, t != '#') {  //
    std::cin >> elem;
    if (t == '+') {
      strings.insert(elem);
    } else if (t == '-') {
      strings.erase(elem);
    } else if (t == '?') {
      if (strings.find(elem) == strings.end())
        std::cout << "NO" << std::endl;
      else
        std::cout << "YES" << std::endl;
    }
  }
  return 0;
}