#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <complex>
//#pragma GCC optimize("O3")
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fo(i, n) for (int i = 0; i < n; ++i)
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define mp make_pair
#define out(t, a) {copy(all(a), ostream_iterator<t>(cout, " ")); cout << '\n';}
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
struct pt {
      int x;
      int y;
      pt() : x(0), y(0)
      {}
};
istream& operator>>(istream& is, pt& p) {
      is >> p.x >> p.y;
      return is;
}
ostream& operator<<(ostream& os, pt& p) {
      os << p.x << " " << p.y;
      return os;
}
vector<pair<int, ll>> g[100000];
vector<ll> a;
void dfs(int v, int p, ll c) {
    for (auto u: g[v]) {
        if (u.f != p) {
            a[u.f] = c^u.s;
            dfs(u.f, v, a[u.f]);
        }
    }
}
struct nd{
    int l, r, t;
};
int main()
{
    io;
    int n, m;
    cin >> n >> m;
    int k = 0, tk = n*m, i = 1;
    vector<int> a;
    while (1) {
        a.pb(i);
        tk -= i;
        i++;
        if (tk <= a.back()) {
            a.back() += tk;
            break;
        }
    }
    vector<int> b;
    for (int i = 0; i < a.size(); ++i) {
        b.pb(a[i]);
        if (a.size() == b.size()) break;
        b.pb(a[a.size() - 1 - i]);
        if (a.size() == b.size()) break;
    }
    char l = 'A';
    vector<string> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i].resize(m);
        if (i % 2) {
            for (int j = 0; j < m; ++j) {
                if (b[k] == 0) {
                    ++k;
                    if (l == 'Z') {
                        l = 'A';
                    } else {
                        ++l;
                    }
                }
                --b[k];
                ans[i][j] = l;
            }
        } else {
            for (int j = m - 1; j >= 0; --j) {
                if (b[k] == 0) {
                    ++k;
                    if (l == 'Z') {
                        l = 'A';
                    } else {
                        ++l;
                    }
                }
                --b[k];
                ans[i][j] = l;
            }
        }
    }
    cout << a.size() << '\n';
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
