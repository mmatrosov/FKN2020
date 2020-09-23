#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

ll INF = (ll) 1e20;
int iINF = (int) 1e20;
ll mod = (ll) 1e9 + 7;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    fast
    ll n;
    cin >> n;
    if(n == 1) {
        cout << "YES";
        return 0;
    }
    cout << ((n + 4) % 4 == 0 ? "YES" : "NO");
}
