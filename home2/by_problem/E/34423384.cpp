#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, pair<long long, long long>> m;
    size_t amount;
    string student;
    long long mark;
    cin >> amount;
    for (size_t i = 0; i < amount; ++i) {
        cin >> student >> mark;
        m[student].first += mark;
        m[student].second += 1;
        cout << m[student].first / m[student].second << '\n';
    }
}