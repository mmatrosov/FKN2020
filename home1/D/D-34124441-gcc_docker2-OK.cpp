#include <iostream>
#include <sstream>
using namespace std;

int main() {
        string keys;
        getline(cin, keys);

        string current_string;
        int m = 0, l = 0, L = 0, w = 0;
        while (getline(cin, current_string)) {
                m += current_string.size();
                l += 1;
                L = max(L, static_cast<int>(current_string.size()));

                stringstream stream(current_string);
                string one_word;

                while (stream >> one_word) {
                        ++w;
                }
        }

        bool values[4]{0, 0, 0, 0};
        stringstream keys_stream(keys);
        string key;
        while (keys_stream >> key) {
                if (key == "-l") {
                        values[0] = true;
                } else if (key == "-w") {
                        values[1] = true;
                } else if (key == "-m") {
                        values[2] = true;
                } else if (key == "-L") {
                        values[3] = true;
                }
        }

        if (values[0]) {
                cout << l << ' ';
        }
        if (values[1]) {
                cout << w << ' ';
        }
        if (values[2]) {
                cout << m + l << ' ';
        }
        if (values[3]) {
                cout << L << ' ';
        }
        cout << endl;
}
