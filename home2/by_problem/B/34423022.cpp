#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    char command;
    string word;
    unordered_set<string> s;
    cin >> command;
    while (command != '#') {
        cin >> word;
        if (command == '+') {
            s.insert(word);
        } else if (command == '-') {
            s.erase(word);
        } else {
            if (s.find(word) == s.end())
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        cin >> command;
    }
}