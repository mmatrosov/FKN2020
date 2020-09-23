#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
    size_t stu_am, query_am, ind;
    deque<string> students;
    string name, location;
    cin >> stu_am;
    for (size_t i = 0; i < stu_am; ++i) {
        cin >> name >> location;
        if (location == "top") {
            students.push_front(name);
        } else {
            students.push_back(name);
        }
    }
    cin >> query_am;
    for (size_t i = 0; i < query_am; ++i) {
        cin >> ind;
        cout << students[--ind] << '\n';
    }
}