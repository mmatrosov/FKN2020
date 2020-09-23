#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>


using namespace std;


int main() {
    int n;
    cin >> n;

    set<int> a;

    int c;
    for (int i = 0; i < n; ++i) {
        cin >> c;

        a.insert(c);
    }

    vector<int> aa;
    for (int x : a) {
        aa.push_back(x);
    }

    int k;
    cin >> k;

    int p;
    for (int i = 0; i < k; ++i) {
        cin >> p;

        cout << lower_bound(aa.begin(), aa.end(), p) - aa.begin() << '\n';
    }

    return 0;
}
