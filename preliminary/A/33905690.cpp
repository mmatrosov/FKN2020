#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES";
            return 0;
    }
    for (int i = 0; i < n; i++) {
        if ((i - 2) * 4 + 4 == n) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
