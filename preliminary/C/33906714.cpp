//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC target("popcnt")
//#pragma GCC target("sse4")
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rng(a) a.begin(),a.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) (int)(a.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef long double ld;















signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(rng(a));
    auto last = unique(rng(a));
    a.erase(last, a.end());
    int k;
    cin >> k;
    vector<pair<int,int> > ww;
    for (int j = 0;j < k; j++){
        int f;
        cin >> f;
        ww.pb({f, j});
    }
    sort(rng(ww));
    vector<int> ans(k);
    int now = -1;
    for (int j = 0; j < k; j++){
        while (now + 1 < a.size() && a[now + 1] < ww[j].fi) now++;
        ans[ww[j].se] = now + 1;
    }
    for(auto x : ans){
        cout << x << endl;
    }
}
