#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <cmath>
#include <vector>
#include <bitset>
#include <iomanip>


using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
    int n, x;
    cin >> n;
    set<int> b;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!b.count(x)) {
            b.insert(x);
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x < a[0]) {
            cout << 0 << endl;
        } else {
            auto c = lower_bound(a.begin(), a.end(), x);
            cout << distance(a.begin(), c) << endl;
        }
    }

}
