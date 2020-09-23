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
    int n;
    cin >> n;
    a.resize(n);
    fo(i, n-1){
        int x, y;
        ll c;
        cin >> x >> y >> c;
        g[x-1].pb({y-1, c});
        g[y-1].pb({x-1, c});
    }
    a[0] = 0;
    dfs(0, -1, 0);
    vector<nd> b;
    b.pb({0, 0, 0});
    fo(i, n) {
        int v = 0;
        fo(j, 32) {
            int x = 1&(a[i]>>(31-j));
            if (x) {
                if (!b[v].r) {
                    b[v].r = b.size();
                    b.pb({0, 0, 0});
                }
                v = b[v].r;
            } else {
                if (!b[v].l) {
                    b[v].l = b.size();
                    b.pb({0, 0, 0});
                }
                v = b[v].l;
            }
        }
        b[v].t = i;
    }
    int q = 0, p = 0;
    fo(i, n) {
        int v = 0;
        fo(j, 32) {
            int x = 1&(a[i]>>(31-j));
            if (!x) {
                if (!b[v].r) {
                    v = b[v].l;
                } else {
                    v = b[v].r;
                }
            } else {
                if (!b[v].l) {
                    v = b[v].r;
                } else {
                    v = b[v].l;
                }
            }
        }
        int t = b[v].t;
        if ((a[i]^a[t]) > (a[q]^a[p])) {
            q = i;
            p = t;
        }
    }
    cout << q + 1 << ' ' << p + 1 << '\n';
    return 0;
}
