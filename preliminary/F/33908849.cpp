#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <unordered_map>


using namespace std;


#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

#define int long long
#define eb emplace_back
#define pb push_back
#define ld long double
#define f first
#define s second
#define deb(a) cerr << #a << " = " << a << '\n';
#define fast() { \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout << fixed << setprecision(20); \
    cerr << fixed << setprecision(11); \
}



const int INF = 1e9 + 7;
const ld EPS = 1e-10;
const int MAXI = 20000;
const int MOD = 998244353;
const int MAXST = 2000000;
const int P = 62;
const ld PI = 3.14159265358979323;

ostream &operator<<(ostream &stream, const pair <int, int> &p) {
    stream << p.first << ' ' << p.second << ' ';
    return stream;
}


int a[100];
int dp[100][200];
int pr[100][200];
vector < int > ans;

signed main() {
    /* freopen("cipher.in", "r", stdin);
     freopen("cipher.out", "w", stdout);*/
    fast();
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++){
        for (int p = 1; p <= k; p++){
            int maxx = a[i], pos = i;
            for (int j = 0; j < i; j++){
                int x = dp[j][p - 1] + a[j + 1] * (i - j);
                if (x > maxx) {
                    maxx = x;
                    pos = j + 1;
                }
            }
            dp[i][p] = maxx;
            pr[i][p] = pos;
        }
    }
    int p = k, x = n - 1;
    for (; p > 0 && x >= 0; ){
        ans.eb(a[pr[x][p]]);
        x = pr[x][p] - 1;
        p--;
    }
    for (; ans.size() < k; ans.eb(INF));
    sort(ans.begin(), ans.end());
    for (auto i: ans)
        cout << i << ' ';

    return 0;
}