/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
*/


#include <bits/stdc++.h>


using namespace std;


#define int long long
#define double long double
#define _USE_MATH_DEFINES


const double eps = 1e-9;


void warp()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}


double len(int x, int y)
{
    double ans = x * x + y * y;
    return sqrt(ans);
}


void solve()
{
    cout.precision(10);
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    double first = len(xa, ya);
    double second = len(xb, yb);
    double ans = first + second;
    double angle = abs(atan2(xa * yb - xb * ya, xa * xb + ya * yb));
    ans = min(ans, min(first, second) * angle + abs(first - second));
    cout << ans << endl;
}


signed main()
{
    warp();
    solve();
    return 0;
}
