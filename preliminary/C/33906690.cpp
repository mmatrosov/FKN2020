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
int x,y,z,n,m,k,l,r,t,mi,x2,y2,z2,x3,y3,x4,y4,f,a[101000],b[101000],d[101000],dp[101000],p[101000];
int ans,ans2,ma=0;
string s,s2,s3;
char c[100100];

struct pos
{
    int x,y,num;
};

bool cmp(pos l,pos r)
{
    if(l.x==r.x)return l.y<r.y;
    return l.x<r.x;
}

vector<pos>v;

int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        if(i==1||a[i]!=a[i-1])v.push_back(pos{a[i],1,0});
    }

    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x;
        v.push_back(pos{x,0,i});
    }
    sort(v.begin(),v.end(),cmp);
    x=0;
    for(i=0;i<v.size();i++)
    {
        if(v[i].y)x++;
        else d[v[i].num]=x;
    }
    for(i=1;i<=m;i++)
    {
        cout<<d[i]<<endl;
    }


}

