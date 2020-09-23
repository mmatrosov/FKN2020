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
ll x,y,z,n,m,k,l,r,t,mi,x2,y2,z2,x3,y3,x4,y4,f,a[101000],d[101000],dd[3301000][2],dp[7301000];
ll ans,ans2,ma=0;
string s,s2;
char c[100100];
vector<ll>v[101000],v2[101010];


void dfs(int x,int y,ll su)
{
    d[x]=su;
    for(int i=0;i<v[x].size();i++)
    {
        ll to=v[x][i],w=v2[x][i];
        if(to!=y)dfs(to,x,(su^w));
    }
}

void ad(int ve,ll ch,int h,int num)
{
    if(h==-1)
    {
        dp[ve]=num;
        return;
    }
    int bi=0;
    if(ch&(1ll<<h))bi=1;
    if(!dd[ve][bi])
    {
        k++;
        dd[ve][bi]=k;
    }
    ad(dd[ve][bi],ch,h-1,num);
}

int fi(int ve,ll ch,int h)
{
    if(h==-1)
    {
        return dp[ve];
    }
    int bi=0;
    if(ch&(1ll<<h))bi=1;
    if(!dd[ve][1-bi])
    {
        return fi(dd[ve][bi],ch,h-1);
    }
    else return fi(dd[ve][1-bi],ch,h-1);
}

int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y>>z;
        v[x].push_back(y);
        v[y].push_back(x);

        v2[x].push_back(z);
        v2[y].push_back(z);
    }
    dfs(1,0,0);ma=0;l=1;r=1;
    for(i=1;i<=n;i++)
    {
        ad(0,d[i],31,i);
        x=fi(0,d[i],31);
        //cout<<d[i]<<' '<<x<<' '<<i<<endl;
        if(ma<(d[x]^d[i]))ma=(d[x]^d[i]),l=x,r=i;
    }
    cout<<l<<' '<<r;

}


