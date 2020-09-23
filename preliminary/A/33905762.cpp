#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES" << endl;
        return 0;
    }
    cout << (((n - 4) % 4 == 0) ? "YES" : "NO") << endl;
    return 0;
}
