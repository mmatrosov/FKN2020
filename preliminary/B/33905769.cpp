#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using vi = vector<int>;
#define f(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define fk(n) for(int k = 0; k < n; k++)
#define ci(n) cin >> n;
#define ic(n) int n; cin >> n;
#define lc(n) int n; cin >> n;
#define all(a) a.begin(), a.end()
#define pri(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sc(a, n) int a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define scl(a, n) ll a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define ft first
#define int long long
const int inf = 2e9, maxn = 1e6, mod = 1e9 + 7;


void solve()
{

}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k[2], b[2];
    cin >> k[0] >> b[0] >> k[1] >> b[1];
    if(k[0] == k[1])
    {
        if(b[0] == b[1]) cout << "coincide";
        else cout << "parallel";
    }
    else
    {
        cout << "intersect\n";
        long double x = (double)(b[1] - b[0]) / (double)(k[0] - k[1]), y = k[0] * x + b[0];
        cout.precision(30);
        cout << x << ' ' << y;

    }
}
