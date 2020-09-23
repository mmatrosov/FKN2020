#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define F first
#define S second
#define forn(i,n) for(int32_t i=0;i<(n);++i)

using namespace std;
using namespace __gnu_pbds;
const int N = 2e5+5;
const int INF = 1e18+7;
const int MOD = 1e9+7;
const double EPS = 1e-8;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> SET;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<> rnd01(0,1);

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n; cin>>n;
    SET s;
    forn(i,n){
        int x; cin>>x;
        s.insert(x);
    }
    int k;
    cin>>k;
    forn(i,k){
        int x; cin>>x;
        cout<<s.order_of_key(x)<<endl;
    }
}
