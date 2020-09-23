#include <bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native") */

//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ss second
#define ff first
#define int long long
//#define double long double
#define pb push_back

const int N = 2e6 + 51, MOD = 1e9 + 7, mod = 998244353,INF = 2e18;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;


signed main() {
    #ifdef Flash
     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES";
        return 0;
    }
    for (int i = 2; i <= N; i++) {
        int x = 2 * i + 2 * (i - 2);
        if (x == n) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO";

}
