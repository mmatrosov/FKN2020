#include <bits/stdc++.h>
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define len(a) (int) (a).size()
#define forn(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define int long long
using namespace std;
void solve();
mt19937 rnd(2007);
signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    swap(rng, rnd);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> path;
    forn (i, n){
        forn (j, m){
            if (i % 2 == 0){
                path.push_back({i, j});
            }
            else {
                path.push_back({i, m - j - 1});
            }
        }
    }
    vector<int> szs;
    int curpl = n * m;
    for (int i = 1;; ++i){
        if (curpl >= i) {
            szs.push_back(i);
            curpl -= i;
        }
        else {
            szs[len(szs) - 1] += curpl;
            break;
        }
    }
    vector<int> ps(len(szs) + 1); forn (i, len(szs)) ps[i + 1] = ps[i] + szs[i];


    string tmpl; forn (kek, m) tmpl += '.';


    start:;
    bool good = true;
    vector<string> ans(n, tmpl);
    for (int i = 0; i < len(szs); ++i){
        vector<char> adj;
        for (int j = ps[i]; j < ps[i + 1]; ++j){
            for (int dx = -1; dx <= 1; ++dx){
                for (int dy = -1; dy <= 1; ++dy){
                    if (abs(dx) + abs(dy) != 1)
                        continue;
                    int x = path[j].first + dx, y = path[j].second + dy;
                    if (0 <= x && x < n && 0 <= y && y < m && ans[x][y] != '.'){
                        adj.push_back(ans[x][y]);
                    }
                }
            }
        }
        sort(all(adj)); adj.resize(unique(all(adj)) - adj.begin());
        if (len(adj) == 26){
            good = false;
            break;
        }
        char mex_sym = 'A';
        int cur = 0;
        while (cur < len(adj) && adj[cur] == mex_sym){
            ++mex_sym;
            ++cur;
        }
        for (int j = ps[i]; j < ps[i + 1]; ++j){
            // cout << j << ' ' << path[j].first << ' ' << path[j].second << endl;
            ans[path[j].first][path[j].second] = mex_sym;
        }
        // cout << endl;
    }

    if (!good) {
        shuffle(all(szs), rnd);
        goto start;
    }
    cout << len(szs) << endl;
    for (auto i : ans)
        cout << i << endl;
}
