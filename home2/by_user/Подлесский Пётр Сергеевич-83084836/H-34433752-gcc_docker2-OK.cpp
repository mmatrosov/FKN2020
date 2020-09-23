#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    size_t con_am, stu_am;
    int mark;
    string name;
    set<string> names;
    map<string, vector<int>> students;
    cin >> con_am;
    vector<int> marks(con_am);
    for (size_t i = 0; i < con_am; ++i) {
        cin >> stu_am;
        for (size_t j = 0; j < stu_am; ++j) {
            cin >> name >> mark;
            if (names.find(name) == names.end()) {
                marks.clear();
                marks.resize(con_am);
                students[name] = marks;
            }
            names.insert(name);
            students[name][i] = mark;
        }
    }
    for (auto st : names) {
        cout << st;
        for (auto m : students[st]) {
            cout << '\t' << m;
        }
        cout << '\n';
    }
}