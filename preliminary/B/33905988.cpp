// Bippolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;
typedef long double ld;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Line {
    ll k, b;

    Line() {
        cin >> k >> b;
    }

    bool operator ==(Line other) {
        return other.k == k && other.b == b;
    }
};

int main() {
    Line line_1;
    Line line_2;
    if (line_1 == line_2) {
        cout << "coincide" << endl;
        return 0;
    }
    if (line_1.k == line_2.k) {
        cout << "parallel" << endl;
        return 0;
    }
    cout << "intersect" << endl;
    ld x = (ld)(line_1.b - line_2.b) / (ld)(line_2.k - line_1.k);
    ld y = line_1.k * x + line_1.b;
    cout << fixed << setprecision(12) << x << " " << y << endl;
    return 0;
}
