#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    set<int> diego;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        diego.insert(a);
    }
    vector<int> stic;
    for (int i : diego) {
        stic.push_back(i);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        int z = lower_bound(stic.begin(), stic.end(), a) - stic.begin();
        cout << z << "\n";
    }

    return 0;
}
