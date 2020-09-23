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
#define scl(a, n) ll a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define sc(a, n) int a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define ft first
#define int long long

const int inf = 1e9, maxn = 2e5, mod = 998244353;

struct Vector
{
    int x, y;
    Vector(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
int operator * (Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}
int operator % (Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}
Vector operator - (Vector a)
{
    return Vector(-a.x, -a.y);
}
bool operator == (Vector a, Vector b)
{
    return ((a * b) > 0) && ((a % b) == 0);
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve()
{

}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ic(n)
    vector<int> a(n);
    f(n) cin >> a[i];
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    ic(k)
    f(k)
    {
        ic(p)
        cout << lower_bound(all(a), p) - a.begin() << '\n';
    }
}
