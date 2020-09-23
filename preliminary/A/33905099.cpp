/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
*/


#include <bits/stdc++.h>


using namespace std;


#define int long long


void warp()
{
    //1freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}


void solve()
{
    int k;
    cin >> k;
    if (k == 1 || k % 4 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}


signed main()
{
    warp();
    solve();
    return 0;
}
