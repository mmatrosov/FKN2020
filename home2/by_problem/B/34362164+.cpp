#include <iostream>
#include <set>
#include <unordered_set>


const int MOD = 1e9 + 7;

//
int hash_func(const std::string& s) {
  long h = 0, st = 1;
  for (int i = 0; i < s.size(); ++i) {
    h = (h + (s[i] - 'a' + 1) * st) % MOD;
    st = (st * 27) % MOD;
  }
  return h;
}

int main() {
  std::unordered_set<int> strings;
  std::string s;
  char type;
  std::cin >> type;
  while (type != '#') {
    std::cin >> s;
    if (type == '+') {
      strings.insert(hash_func(s));
    } else if (type == '-') {
      strings.erase(hash_func(s));
    } else {
      if (strings.find(hash_func(s)) != strings.end()) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    }
    std::cin >> type;
  }
  return 0;
}