#include <iostream>
#include <map>
#include <set>
#include <vector>

int scalar(std::vector<int> &a, std::vector<int> &b, int n) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += a[i] * b[i];
  }
  return res;
}

int main() {
  int m, n;
  std::cin >> m >> n;
  std::string first;
  std::cin >> first;
  std::vector<int> n_size = {1, 2, 3};
  for (int i = 0; i < n; i++) {
    std::cin >> n_size[i];
  }
  int ans = std::numeric_limits<int>::min();
  std::vector<std::string> answer;
  std::vector<int> now(n);
  for (int i = 1; i < m; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < n; ++j) {
      std::cin >> now[j];
    }
    int now_res = scalar(n_size, now, n);
    if (now_res > ans) {
      ans = now_res;
      answer = {s};
    } else if (now_res == ans) {
      answer.push_back(s);
    }
  }
  for (auto &el : answer) {
    std::cout << el << "\n";
  }

  return 0;
}
