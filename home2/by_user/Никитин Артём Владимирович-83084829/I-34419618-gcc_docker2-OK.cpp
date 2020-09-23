#include <iostream>
#include <map>
#include <string>
#include <vector>

int scalar(const std::vector<int>& a, const std::vector<int>& b) {
  int scal = 0;
  for (int i = 0; i < a.size(); i++) {
    scal += a[i] * b[i];
  }
  return scal;
}

int main() {
  int m, n;
  std::cin >> m >> n;
  std::map<int, std::vector<std::string>> scalars;
  std::string word;
  std::vector<int> coordinates(n);
  std::cin >> word;
  for (int i = 0; i < n; i++) std::cin >> coordinates[i];
  m--;
  while (m--) {
    std::vector<int> new_coordinates(n);
    std::cin >> word;
    for (int i = 0; i < n; i++) std::cin >> new_coordinates[i];
    scalars[scalar(coordinates, new_coordinates)].push_back(word);
  }
  const std::vector<std::string> lowest_scalar = scalars.rbegin()->second;
  for (const std::string& answer : lowest_scalar) std::cout << answer << '\n';
}
