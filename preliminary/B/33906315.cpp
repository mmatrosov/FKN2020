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
    double k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    cout.precision(20);
    if (abs(k1 - k2) < eps) {
        if (abs(b1 - b2) < eps) cout << "coincide\n";
        else cout << "parallel\n";
    } else {
        cout << "intersect\n";
        double x = (b2 - b1) / (k1 - k2);
        double y = k1 * x + b1;
        cout << x << " " << y << "\n";
    }
    return 0;
}