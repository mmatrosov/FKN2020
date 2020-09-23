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

double dist(double x1, double y1, double x2, double y2){
    return (double)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double ans = dist(x1,y1,0,0) + dist(x2,y2,0,0);
    if( (x1==0 && y1==0) || (x2==0 && y2==0) ){
        
    }else{
        double a = dist(x1,y1,x2,y2);
        double b = dist(x1,y1,0,0);
        double c = dist(x2,y2,0,0);
        double angle = (double)acos((double)(b*b+c*c-a*a)/(double)(2*b*c));
        double delta = abs(b-c);
        double mb = delta+angle*b;
        if(ans>mb){
            ans=mb;
        }
        mb = delta+angle*c;
        if(ans>mb){
            ans=mb;
        }
    }
    cout<<setprecision(10)<<fixed<<ans<<endl;
}
