#include <iostream>
#include <string>

using namespace std;

const string chars = "0123456789ABCDEF";

int main() {
    cout << '\t';
    for (int j = 0; j < 16; j++) {
        cout << chars[j] << '\t';
    }
    cout << endl;
    for (int i = 2; i < 8; i++) {
        cout << chars[i] << '\t';
        for (int j = 0; j < 16; j++) {
            cout << static_cast<char>(i * 16 + j) << '\t';
        }
        cout << '\n';
    }
    return 0;
}
