#include <iostream>
using namespace std;

int main() {
        cout << hex << uppercase << '\t';
        for (int col = 0; col < 16; ++col) {
                cout << col << '\t';
        }
        cout << dec << endl;

        for (int row = 2; row < 8; ++row) {
                cout << row << '\t';
                for (int col = 0; col < 16; ++col) {
                       cout << char(row * 16 + col) << '\t';
                }
                cout << endl;
        }
}

