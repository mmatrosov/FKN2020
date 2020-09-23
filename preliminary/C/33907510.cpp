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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}


int q(vector<int> &a, int p)
{
    if (a.size() == 0) return 0;
    int l = -1, r = a.size();
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (a[m] >= p) r = m;
        else l = m;
    }
    return l + 1;
}


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> b;
    if (n > 0) b.push_back(a[0]);
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > a[i - 1]) b.push_back(a[i]);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int p;
        cin >> p;
        cout << q(b, p) << "\n";
    }
    cout << endl;

}


signed main()
{
    warp();
    solve();
    return 0;
}
