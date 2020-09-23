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
ll x,y,z,n,m,k,l,r,t,mi,x2,y2,z2,x3,y3,x4,y4,f,a[101000],b[101000],d[101000],dp[110][110],pr[110][110];
int ans,ans2,ma=0;
string s,s2,s3[30000],ss;
char c[100100];
vector<int>v;
int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0){n--;i--;}
    }
    sort(a+1,a+n+1);
    for(i=0;i<=n;i++)for(j=1;j<=n;j++)dp[i][j]=-1e9;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(dp[i][j]<0)continue;
            for(k=i+1;k<=n;k++)
            {
                if(dp[k][j+1]<dp[i][j]+a[i+1]*(k-i))dp[k][j+1]=dp[i][j]+a[i+1]*(k-i),pr[k][j+1]=i;
            }
        }
        //for(j=0;j<=i;j++)if(dp[i+1][j]<dp[i][j])dp[i+1][j]=dp[i][j],pr[i+1][j]=pr[i][j];
    }
    ma=0;x=0;
    for(i=0;i<=m;i++)if(ma<dp[n][i])ma=dp[n][i],x=i;
    y=n;
    for(i=x;i>=1;i--)
    {
        d[i]=a[pr[y][i]+1];
        y=pr[y][i];
    }
    for(i=x+1;i<=m;i++)
     {
         d[i]=d[i-1]+1;
     }
     for(i=1;i<=m;i++)cout<<d[i]<<' ';
}


