#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  size_t m, n;
  cin >> m >> n;

  vector<string> strings(m);
  for (size_t i = 0; i < m; i++) {
    cin >> strings[i];
  }

  map<string, size_t> cnt;
  for (size_t i = n - 1; i < m; i++) {
    string curr;
    for (size_t j = i - (n - 1); j <= i; j++) {
      curr += strings[j] + " ";
    }
    cnt[curr]++;
  }

  vector<pair<size_t, string>> ordered;
  for (const auto& el : cnt) {
    ordered.push_back({-el.second, el.first});
  }
  sort(ordered.begin(), ordered.end());
  for (const auto& el : ordered) {
    cout << el.second << "- " << -el.first << '\n';
  }
}
