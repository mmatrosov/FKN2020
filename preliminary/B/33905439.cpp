#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define endl "\n"
#define int long long
#define F first
#define S second
#define B begin
#define E end
#define RB rbegin
#define RE rend
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int INF = 1e9 + 1;
const double EPS = 1e-10;
const ll P = 1e9 + 7;
const int Q = 47;
 
using namespace std;
 
void hello()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
 
void show(vector<int>& arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}
void show(vector<vector<int>>& arr)
{
    for (auto i : arr)
        show(i);
    cout << endl;
}


signed main()
{
    hello();
    
    int k1, k2, b1, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2 && b1 == b2)
        cout << "coincide" << endl;
    else if (k1 == k2)
        cout << "parallel" << endl;
    else
    {
        cout << "intersect" << endl;
        double x = (double)(b2 - b1) / (k1 - k2);
        double y = k1 * x + b1;
        cout << fixed << setprecision(17) << x << " " << y << endl;
    }
}