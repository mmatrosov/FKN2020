#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

ll INF = (ll) 1e20;
int iINF = (int) 1e20;
ll mod = (ll) 1e9 + 7;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
char tb[1000][1000];
vector<pair<ll, ll>> v;

void go(ll i, ll j, ll left) {
    if (tb[i][j] == '$')
        tb[i][j] = '@';
    v.push_back({i, j});
    --left;
    if (left == 0) {
        return;
    }
    if (j + 1 < m) {
        if (tb[i][j + 1] == '$') {
            go(i, j + 1, left);
            return;
        }
    }
    if (j - 1 >= 0) {
        if (tb[i][j - 1] == '$') {
            go(i, j - 1, left);
            return;
        }
    }
    if (i + 1 < n) {
        if (tb[i + 1][j] == '$') {
            go(i + 1, j, left);
            return;
        }
    }
}

char get(ll i, ll j) {
    if (i >= 0 && i < n && j >= 0 && j < m) {
        if (tb[i][j] == '@')
            return '$';
        return tb[i][j];
    }
    return '$';
}

signed main() {
    fast
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            tb[i][j] = '$';
        }
    }
    ll ost = n * m;
    ll now = 1;
    pair<ll, ll> id = {0, 0};
    char lst;
    while (now <= ost) {
        go(id.first, id.second, now);
        pair<ll, ll> last = v[v.size() - 1];
        vector<bool> ok(26, true);
        for (auto i : v) {
            char c = get(i.first, i.second + 1);
            if (c != '$')
                ok[c - 'a'] = false;
            c = get(i.first, i.second - 1);
            if (c != '$')
                ok[c - 'a'] = false;
            c = get(i.first + 1, i.second);
//            cout << c << ' ' << i.first + 1 << ' ' << i.second << endl;
            if (c != '$')
                ok[c - 'a'] = false;
            c = get(i.first - 1, i.second);
            if (c != '$')
                ok[c - 'a'] = false;
        }
//        cout << now << endl;
        char nw = '$';
        for (int i = 0; i < 26; ++i) {
            if (ok[i]) {
                nw = 'a' + i;
                break;
            }
        }
        if (nw == '$') {
            while (true) {}
        }
        ost -= now;
        if (now + 1 > ost) {
            nw = 'z';
        }
        for (auto i : v) {
            tb[i.first][i.second] = nw;
        }
        v.clear();
        if (ost) {
            go(last.first, last.second, 2);
            id = v.back();
            v.clear();
            tb[id.first][id.second] = '$';
        }
        ++now;
        lst = nw;
    }
    cout << now - 1 << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (tb[i][j] == '$')
                tb[i][j] = lst;
            cout << (char) (tb[i][j] + 'A' - 'a');
        }
        cout << '\n';
    }
}

