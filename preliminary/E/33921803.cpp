#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define ld long double
#define ull unsigned long long
#define mp make_pair

using namespace std;

void init() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef TEST
    freopen("!inp", "r", stdin);
    freopen("!out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const ll maxn = 1e3;

ll tree[maxn];

ll f(ll x) {
    return x & (x + 1);
}

void add(ll pos, ll val) {
    while (pos < maxn) {
        tree[pos] += val;
        pos |= (pos + 1);
    }
}

ll prefsum(ll pos) {
    ll ans = 0;
    while (pos >= 0) {
        ans += tree[pos];
        pos = f(pos) - 1;
    }
    return ans;
}

void tolow(string &s) {
    int d = 'A' - 'a';
    for (auto &ev : s) {
        if ('A' <= ev && ev <= 'Z')
            ev -= d;
    }
}

bool isnumber(char x) {
    return '0' <= x && x <= '9';
}

bool isletter(char x) {
    return (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'));
}

bool maybe(string &s) {
    int cntnum = 0;
    int cntlet = 0;
    int cntz = 0;
    for (auto ev : s) {
        if (isnumber(ev))
            cntnum++;
        else if (isletter(ev))
            cntlet++;
        else if (ev == '_')
            cntz++;
        else
            return false;
    }
    if (cntlet + cntz + cntnum == 0)
        return false;
    if (cntlet + cntz == 0)
        return false;

    return true;
}

int main() {
    init();

    string s;

    int n;
    cin >> n;

    cin >> s;

    bool low = (s == "no");
    cin >> s;
    bool begnumber = (s == "yes");

    set<string> key;

    while (n--) {
        cin >> s;
        if (low)
            tolow(s);
        key.insert(s);
    }

    map<string, pair<int, int>> bar;

    int cnt = 0;

    stringstream str;

    while (cin >> s) {
        for (auto &ev : s)
            if (!isnumber(ev) && !isletter(ev) && ev != '_')
                ev = ' ';
        s += " ";
        str << " ";
        str << s;
    }

    while (str >> s) {
        if (low)
            tolow(s);

        if (key.count(s))
            continue;

        if (!begnumber && isnumber(s[0]))
            continue;

        if (maybe(s))
            if (bar.count(s))
                bar[s] = {bar[s].ff + 1, bar[s].ss};
            else
                bar[s] = {bar[s].ff + 1, cnt};
        cnt++;
    }

    string ans = "";
    pair<int, int> maxi = {0, 0};

    for (auto ev : bar) {
        if (ev.ss.ff > maxi.ff) {
            maxi = ev.ss;
            ans = ev.ff;
        }
        if (ev.ss.ff == maxi.ff && ev.ss.ss < maxi.ss) {
            maxi = ev.ss;
            ans = ev.ff;
        }
    }
    cout << ans << endl;

    return 0;
}