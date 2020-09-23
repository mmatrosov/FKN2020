#include <iostream>

using namespace std;

bool solve(int n) {
    if (n == 1) {
        return true;
    } else if (n % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int input;
    cin >> input;
    if (solve(input)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
