#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  string s;
  set<char> ans;
  cin >> s;
  for (auto c : s) {
    ans.insert(c);
  }
  while (cin >> s) {
    for (auto c : ans) {
      if (s.find(c) == string::npos) {
        ans.erase(c);  //
      }
    }
  }
  for (auto c : ans) cout << c;
  cout << '\n';
}