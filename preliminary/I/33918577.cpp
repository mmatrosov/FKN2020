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
ll x,y,z,n,m,k,l,r,t,mi,x2,y2,z2,x3,y3,x4,y4,f,a[201000],d[201000],p[201000];
ll ans,ans2,ma=0;
string s,s2;
char c[100100];
vector<ll>v[201000],v2[201010];

struct pos
{
    ll x,di,ko;
};

bool operator<(pos l,pos r)
{
    if(l.di==r.di)return l.ko<r.ko;
    return l.di>r.di;
}

int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m>>k;
    priority_queue<pos>q;
    for(i=1;i<=n;i++)d[i]=1e18;
    for(i=1;i<=k;i++)
    {
        cin>>x;
        q.push(pos{x,0ll,1ll});
        d[x]=0;
    }
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        v[x].push_back(y);
        v[y].push_back(x);
        v2[x].push_back(z);
        v2[y].push_back(z);
    }
    int st=0,fi=0;
    cin>>st>>fi;
    q.push(pos{st,0ll,0ll});
    d[st]=0;
    while(!q.empty())
    {
        while(!q.empty()&&p[q.top().x])q.pop();
        if(q.empty())break;
        x=q.top().x;
        f=q.top().ko;
        q.pop();
        p[x]=f+1;
        for(i=0;i<v[x].size();i++)
        {
            ll to=v[x][i],w=v2[x][i];
            if(!p[to]&&d[to]>d[x]+w)
            {
                d[to]=d[x]+w;
                q.push(pos{to,d[to],f});
            }
        }
    }
    if(p[fi]!=1)cout<<-1;
    else cout<<d[fi];
}


