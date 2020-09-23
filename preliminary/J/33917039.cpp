#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;

const int N = 2e3 + 10;
int a[N][N];
bool gr[N][N];
vector<int> g[N];
int col[N];

void dfs(int v) {
    bool ban[50] = {};
    for (int to : g[v]) {
        ban[col[to]] = 1;
    }
    for (int i = 1; i <= 26; i++) {
        if (!ban[i]) {
            col[v] = i;
            break;
        }
    }
    for (int to : g[v]) {
        if (!col[to]) {
            dfs(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1;; i++) {
        if (i * (i + 1) / 2 <= n * m) {
            ans = i;
        }
        else {
            break;
        }
    }
    for (int k = 1, i = 1, j = 1; k <= ans; k++) {
        for (int l = 1; l <= k; l++) {
            a[i][j] = k;
            if (j & 1) {
                if (i == n) {
                    j++;
                }
                else {
                    i++;
                }
            }
            else {
                if (i == 1) {
                    j++;
                }
                else {
                    i--;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!a[i][j]) {
                a[i][j] = ans;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i <= n - 1 && a[i][j] != a[i + 1][j]) {
                int u = a[i][j];
                int v = a[i + 1][j];
                gr[u][v] = gr[v][u] = 1;
            }
            if (j <= m - 1 && a[i][j] != a[i][j + 1]) {
                int u = a[i][j];
                int v = a[i][j + 1];
                gr[u][v] = gr[v][u] = 1;
            }
        }
    }
    for (int i = 1; i <= ans; i++) {
        for (int j = 1; j <= ans; j++) {
            if (gr[i][j]) {
                g[i].pb(j);
            }
        }
    }
    for (int i = 1; i <= ans; i++) {
        if (!col[i]) {
            dfs(i);
        }
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << char('A' + col[a[i][j]] - 1);
        }
        cout << "\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
