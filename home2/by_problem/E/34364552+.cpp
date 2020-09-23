#include <iostream>
#include <map>
#include <string>

struct mark {
  uint64_t sum = 0, num = 0;  //
};

int main() {
  std::map<std::string, mark> counter;
  int n;
  uint64_t new_mark;
  std::string name;

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> name >> new_mark;
    counter[name].num++;
    counter[name].sum += new_mark;
    std::cout << counter[name].sum / counter[name].num << std::endl;
  }
  return 0;
}
