#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> data;
    int num;
    while (cin >> num) {
        if (data.find(num) == data.end()) {
            cout << "NO\n";
            data.insert(num);
        } else {
            cout << "YES\n";
        }
    }
}