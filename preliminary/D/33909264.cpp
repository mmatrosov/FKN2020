#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ul unsigned long
#define ld long double
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

//typedef tree
//<
//ll,
//null_type,
//less<ll>,
//rb_tree_tag,
//tree_order_statistics_node_update
//> or_st;


int N=1e9+7,M=31,INF=2e9+10;
int i,j;
ll x,y,z,n,m,k,l,r,t,mi,x2,y2,z2,x3,y3,x4,y4,f,a[101000],b[101000],d[101000],dp[101000],p[101000];
int ans,ans2,ma=0;
string s,s2,s3;
char c[100100];

ld F(ld x,ld y,ld x2,ld y2)
{
    return sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
}

void out(ld x)
{
    cout<<fixed<<setprecision(20)<<x;
    exit(0);
}


int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>x>>y>>x2>>y2;
    if(x==x2&&y==y2)out(0);
    ld r=F(x,y,0,0);
    ld R=F(x2,y2,0,0);
    if(r==0)out(R);
    if(R==0)out(r);
    if(r>R){swap(x,x2);swap(y,y2);swap(r,R);}
    ld mi=r+R;

    ld t=R/r,x3=(ld)x2/t,y3=(ld)y2/t;

    ld l=F(x3,y3,x2,y2),tt=F(x,y,x3,y3);
    ld co=1.0-tt*tt/(2.0*r*r),alf=acos(co);
    ld du=r*alf;
    mi=min(mi,l+du);



    out(mi);
}

