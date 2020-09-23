#include <bits/stdc++.h>

#define endl '\n'
#define vc vector
#define sz(v) (int) v.size()
#define endd endl; return 0;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define rep(n, i) for (int i = 0; i < n; ++i)
#define per(n, i) for (int i = n - 1; i >= 0; --i)
#define pr pair
#define fs first
#define sc second
#ifdef LOCAL
#define cerr cout
#else
#define cerr if (0) cout
#endif

using namespace std;

typedef long long ll;

const long long INF = 1e18;
const int N = 1e5 + 5;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int A = 1e6 + 5;

signed main() {
#ifdef LOCAL
    freopen("text.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    string C, D;
    cin >> C >> D;
    bool tolow = 1, digit = 0;
    if (C == "yes") {
        tolow = 0;
    }
    if (D == "yes") {
        digit = 1;
    }
    vc<string> key(n);
    rep(n, i) {
        cin >> key[i];
        if (tolow) {
            rep(sz(key[i]), j) {
                key[i][j] = tolower(key[i][j]);
            }
        }
    }
    sort(all(key));
    char c;
    map<string, int> mp;
    //bool wordst = 0;
    string word = "";
    vc<string> text;
    while ((scanf("%c", &c) != -1)) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_') {
            if (tolow) {
                c = tolower(c);
            }
            word += c;
        } else {
            if (sz(word) > 0) {
                if (word[0] >= '0' && word[0] <= '9' && !digit) {
                    word = "";
                    continue;
                }
                if (sz(word) == 1 && word[0] >= '0' && word[0] <= '9') {
                    word = "";
                    continue;
                }
                if (binary_search(all(key), word)) {
                    word = "";
                    continue;
                }
                mp[word]++;
                text.pb(word);
            }
            word = "";
        }
    }
    rep(1, j) {
        if (sz(word) > 0) {
            if (word[0] >= '0' && word[0] <= '9' && !digit) {
                break;
            }
            if (sz(word) == 1 && word[0] >= '0' && word[0] <= '9') {
                break;
            }
            if (binary_search(all(key), word)) {
                break;
            }
            mp[word]++;
            text.pb(word);
        }
    }
    int ans = 0;
    string a;
    for (auto x : mp) {
        if (x.sc > ans) {
            ans = x.sc;
            a = x.fs;
        }
    }
    for (auto x : mp) {
        if (x.sc == ans) {
            if (find(all(text), x.fs) - text.begin() < find(all(text), a) - text.begin()) {
                a = x.fs;
            }
        }
    }
    cout << a;
    return 0;
}
