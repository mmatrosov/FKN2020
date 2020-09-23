#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define int long long
#define double long double
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define TIME ((clock() - start_time) / CLOCKS_PER_SEC)

using namespace std;
//using namespace __gnu_pbds;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count() + 'd'+'o'+'i'+'n'+'g' + 'g'+'e'+'y');

const int inf = 1e18;
const double eps = 1e-6;
double start_time;


signed main()
{
    start_time = clock();
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int p;
        cin >> p;
        int cnt = lower_bound(all(v), p) - v.begin();
        cout << cnt << "\n";
    }
    return 0;
}