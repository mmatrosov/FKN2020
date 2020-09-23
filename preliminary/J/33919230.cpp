#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define double long double
#define _ << ' ' <<
#define For(i,z) for(int i=0;i<int32_t(z);++i)
#define printObj(a) {for (auto &i : a) cout << i << ' '; cout << '\n';}
#define sqr(a) ((a)*(a))

#define pii pair<int, int>
#define pdd pair<double, double>
#define x first
#define y second

template<typename T>
using orset = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename K>
using ormap = tree <T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename K> inline void umax(T &a, K b) { a = max(a, (T)b); }
template<typename T, typename K> inline void umin(T &a, K b) { a = min(a, (T)b); }
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int32_t N = 3e3 + 10;
const int64_t INF = 1e16;
const pair<int64_t, int64_t> PINF = make_pair(INF, INF);
const double EPS = 1e-7;
const int MOD = 1e9 + 7;
const int II = 1e9 + 10;
const int64_t AMOD = 99194853094755497;
const double PI = 3.14159265359;

int n, m;
char a[N][N];

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	cin >> n >> m;
    deque<int> kings;
    int sum = n*m;
    bool flg = false;
    for (int i = 1; sum >= i; sum -= i, i++) {
        // if (flg) kings.push_back(i); else kings.push_front(i);
        // flg = !flg;
        kings.push_back(i);
    }
    int ans = kings.size();
    kings.back() += sum;
    int d = 1;
    char let = 'A';
    For (i, n) {
        for (int j = d == 1 ? 0 : m-1; 0 <= j && j < m; j += d) {
            a[i][j] = let;
            if (let < 'U') {
                kings.front()--;
                if (!kings.front()) {
                    kings.pop_front();
                    let++;
                }
            } else {
                kings.back()--;
                if (!kings.back()) {
                    kings.pop_back();
                    let = let == 'Z' ? 'A' : let + 1;
                }
            }
        }
        d *= -1;
    }
    cout << ans << '\n';
    For (i, n) {
        For (j, m) cout << a[i][j];
        cout << '\n';
    }
}
