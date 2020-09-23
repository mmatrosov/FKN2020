// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma warning(disable : 4996)

// by ivan esipov

#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
const int maxn = 1e3 + 2;
const int mod = 1e9 + 7;
const int INF = 1e18 + 1;
// const ld eps = 1e-8;
// mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
char aa[maxn][maxn];

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            aa[i][j] = '!';
        }
    }
    int ans = 0;
    int cur = 1;
    int used = 0;
    int posx = 0, posy = 0;
    bool fl = 0;
    while (1) {
        // cout << posx << ' ' << posy << endl;
        if (n * m - used - cur < cur + 1) {
            ans = cur;
            cur = n * m - used;
        }
        used += cur;
        vector<pair<int, int> >where;
        map<char, int>what;
        for (int k = 0; k < cur; k++) {
            where.pb({posx, posy});
            if (posx != 0) {
                what[aa[posx - 1][posy]] = 1;
            }
            if (posy != 0) {
                what[aa[posx][posy - 1]] = 1;
            }
            if (posy != m - 1) {
                what[aa[posx][posy + 1]] = 1;
            }
            if (!fl) {
                if (posy == m - 1) {
                    posx++;
                    fl = 1;
                }
                else {
                    posy++;
                }
            } else {
                if (posy == 0) {
                    posx++;
                    fl = 0;
                } else {
                    posy--;
                }
            }
        }
        char curch = '!';
        for (char z = 'A'; z <= 'Z'; z++) {
            if (!what.count(z)) {
                curch = z;
                break;
            }
        }
        if (curch == '!') return 1;
        for (auto [x, y] : where) {
            aa[x][y] = curch;
        }
        if (ans == 0) cur++;
        else break;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << aa[i][j];
        }
        cout << endl;
    }
    return 0;
}