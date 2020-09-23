#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

vector<vector<pii>> way;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    way.resize(n);
    vector<ll> dum(k);
    vector<ll> stan(n, -1);
    for (ll i = 0; i < k; i++) {
        ll d;
        cin >> d;
        dum[i] = d - 1;
    }
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        way[a].push_back({b, c});
        way[b].push_back({a, c});
    }
    ll f, s;
    cin >> s >> f;
    f--;
    s--;
    set<pii> seti;
    for (ll i : dum) {
        seti.insert({0, i});
    }
    while (!seti.empty()) {
        pii now = *seti.begin();
        seti.erase(now);
        if (stan[now.second] != -1) {
            continue;
        }
        stan[now.second] = now.first;
        for (pii v : way[now.second]) {
            if (stan[v.first] == -1) {
                seti.insert({v.second + now.first, v.first});
            }
        }
    }

    vector<ll> astro(n, -1);
    set<pii> as;
    as.insert({0, s});
    while (!as.empty()) {
        pii now = *as.begin();
        as.erase(now);
        if (astro[now.second] != -1) {
            continue;
        }
        astro[now.second] = now.first;
        if (astro[now.second] >= stan[now.second]) {
            continue;
        }
        for (pii v : way[now.second]) {
            if (astro[v.first] == -1) {
                as.insert({v.second + now.first, v.first});
            }
        }
    }
    if (astro[f] < stan[f] || stan[f] == -1) {
        cout << astro[f];
    } else {
        cout << -1;
    }

    return 0;
}
