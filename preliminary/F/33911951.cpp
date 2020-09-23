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

const int maxn = 150;
ll dp[maxn][maxn][maxn];
int par[maxn][maxn][maxn];

int main() {
    init();

    int n, k;
    cin >> n >> k;

    vector<ll> a;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x == 0)
            continue;
        a.pb(x);
    }
    n = a.size();
    if (n == 0) {
        for (int i = 0; i < k; i++) {
            cout << i + 1 << " ";
        }
        return 0;
    }
    
    if (k >= n) {
        vector<ll> ans = a;
        while (ans.size() < k)
            ans.pb(ans.back() + 1);
        sort(all(ans));
        for (auto ev : ans)
            cout << ev << " ";
        cout << endl;
        return 0;
    }

    a.pb(0);
    sort(all(a));
    n++;

    for (int i = 0; i < n; i++) {
        dp[i][0][0] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int q = 1; q <= k && q <= i; q++) {
            dp[i][q][1] = i * a[1];
            par[i][q][1] = 0;
            for (int last = 2; last <= i; last++) {
                ll cur = a[last] * (i - last + 1);
                for (int pre = 1; pre <= last - 1; pre++) {
                    if (dp[i][q][last] < dp[last - 1][q - 1][pre] + cur) {
                        dp[i][q][last] = dp[last - 1][q - 1][pre] + cur;
                        par[i][q][last] = pre;
                    }
                }
            }
        }
    }

    vector<ll> ans;

    int cur = n - 1;
    for (int i = 0; i < k; i++) {
        int pos = cur;
        for (int j = 1; j <= cur; j++) {
            if (dp[cur][k - i][j] > dp[cur][k - i][pos])
                pos = j;
        }
        ans.pb(a[pos]);
        cur = pos - 1;
    }
    reverse(all(ans));
    for (auto ev : ans)
        cout << ev << " ";
    return 0;
}