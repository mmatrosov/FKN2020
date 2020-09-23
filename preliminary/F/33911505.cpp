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

int n,k;
int a[105];
int dp[105][105];
pair<int,int> p[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n>>k;
    forn(i,n) cin>>a[i];
    forn(i,105) forn(j,105) p[i][j]={-1,-1};
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            for(int z=i+1;z<=n;z++){
                if(dp[z][j+1]<dp[i][j]+a[i]*(z-i)){
                    dp[z][j+1]=dp[i][j]+a[i]*(z-i);
					p[z][j+1]={i,j};
                }
            }
        }
    }
    pair<int,int> cur={n,k};
	vector<int> ans;
	while(cur.F!=-1){
		cur=p[cur.F][cur.S];
		if(cur.F!=-1) ans.push_back(a[cur.F]);
	}
	if(ans.size() == 0) ans.push_back(1);
	while(ans.size()<k) ans.push_back(ans.back()+105);
	sort(ans.begin(),ans.end());
	for(int x : ans) cout<<x<<" ";
}
