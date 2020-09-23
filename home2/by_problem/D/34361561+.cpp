#include <iostream>
#include <set>
#include <string>

int main() {
  std::set<std::string> ans;
  std::string s;
  while (std::cin >> s) {
    int id = 0;
    while (s.find('/', id) != std::string::npos) {
      ans.insert(s.substr(0, s.find('/', id) + 1));
      id = s.find('/', id) + 1;
    }
  }
  for (auto el : ans) {  //
    std::cout << el << '\n';
  }
  return 0;
}