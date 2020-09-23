#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k;
    cin >> k;
    if (k == 1) {
        cout << "YES";
        return 0;
    }
    for (int n = 1; n <= 100000; ++n) {
        if (2 * n + 2 * (n - 2) == k) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
