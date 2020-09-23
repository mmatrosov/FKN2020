#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

struct Student {
  std::string n, sn;
  int d, m, y, b;
  std::vector<std::string> unis;
};

bool operator<(const Student& a, const Student& b) {
  if (a.sn != b.sn) {
    return a.sn < b.sn;
  }
  if (a.n != b.n) {
    return a.n < b.n;
  }
  if (a.y != b.y) {
    return a.y < b.y;
  }
  if (a.m != b.m) {
    return a.m < b.m;
  }
  return a.d < b.d;
}

bool comp_st(Student& a, Student& b) {
  if (a.b != b.b) {
    return a.b > b.b;
  }
  if (a.y != b.y) {
    return a.y < b.y;
  }
  if (a.m != b.m) {
    return a.m < b.m;
  }
  if (a.d != b.d) {
    return a.d < b.d;
  }
  if (a.sn != b.sn) {
    return a.sn < b.sn;
  }
  return a.n < b.n;
}

int main() {
  int n;
  std::cin >> n;
  std::map<std::string, int> pl;
  std::map<std::string, std::set<Student> > univ;
  for (int i = 0; i < n; ++i) {
    std::string uny;
    int cnt;
    std::cin >> uny >> cnt;
    pl[uny] = cnt;
  }
  int st;
  std::cin >> st;
  std::vector<Student> ss(st);
  for (int i = 0; i < st; ++i) {
    std::cin >> ss[i].n >> ss[i].sn >> ss[i].d >> ss[i].m >> ss[i].y >> ss[i].b;
    int unis;
    std::cin >> unis;
    for (int j = 0; j < unis; ++j) {
      std::string uny;
      std::cin >> uny;
      ss[i].unis.push_back(uny);
    }
  }
  std::sort(ss.begin(), ss.end(), comp_st);
  for (int i = 0; i < st; ++i) {
    for (auto uny : ss[i].unis) {
      if (pl[uny] > 0) {
        --pl[uny];
        univ[uny].insert(ss[i]);
        break;
      }
    }
  }
  for (auto u : pl) {
    std::cout << u.first << '\t';
    for (auto s : univ[u.first]) {
      std::cout << s.n << ' ' << s.sn << '\t';
    }
    std::cout << '\n';
  }
  return 0;
}
