#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int MAX_SCORE = 1e9;

struct Student {
  string name, surname;
  int day, month, year, score, ua;
  vector<string> universities;
};

bool operator<(const Student &s1, const Student &s2) {
  return tie(s1.surname, s1.name, s1.year, s1.month, s1.day) <
         tie(s2.surname, s2.name, s2.year, s2.month, s2.day);
}

istream &operator>>(istream &in, Student &s) {
  in >> s.name >> s.surname >> s.day >> s.month >> s.year >> s.score >> s.ua;
  string un;
  for (size_t i = 0; i < s.ua; ++i) {  //
    cin >> un;
    s.universities.push_back(un);
  }
  return in;
}

ostream &operator<<(ostream &out, const Student &s) {
  out << s.name << ' ' << s.surname;
  return out;
}

bool cmp(const Student &s1, const Student &s2) {
  if (s1.score > s2.score) return true;
  if (s1.score < s2.score) return false;
  return tie(s1.year, s1.month, s1.day, s1.surname, s1.name) <
         tie(s2.year, s2.month, s2.day, s2.surname, s2.name);
}

using namespace std;

int main() {
  size_t uni_am, stu_am;
  map<string, pair<size_t, set<Student>>> unis;  //
  string uni;
  size_t cap;
  cin >> uni_am;
  vector<string> v_unis(uni_am);
  for (size_t i = 0; i < uni_am; ++i) {
    cin >> uni >> cap;
    v_unis[i] = uni;
    unis[uni].first = cap;
  }
  sort(v_unis.begin(), v_unis.end());
  cin >> stu_am;
  vector<Student> studs(stu_am);
  for (size_t i = 0; i < stu_am; ++i) {
    cin >> studs[i];
  }
  sort(studs.begin(), studs.end(), cmp);
  for (auto st : studs) {
    for (auto u : st.universities) {
      if (unis[u].first > 0) {
        unis[u].second.insert(st);
        unis[u].first -= 1;
        break;
      }
    }
  }
  for (auto u : v_unis) {
    cout << u << '\t';
    for (auto s : unis[u].second) {
      cout << s << '\t';
    }
    cout << '\n';
  }
}