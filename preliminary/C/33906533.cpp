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
    map<ll, ll> num;
    set<ll> st;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        num[a[i]]++;
        st.insert(a[i]);
    }
    map<ll, ll> mp;
    ll num_before = 0;
    for (auto i : num) {
        mp[i.first] = num_before;
        num_before++;
    }
    ll k;
    cin >> k;
    while (k--) {
        ll x;
        cin >> x;
        auto i = st.lower_bound(x);
        if (i == st.end()) {
            cout << st.size() << '\n';
        } else {
            cout << mp[(*i)] <<
                 '\n';
        }
    }
}
