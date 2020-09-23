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
vector<int>v[101000];

int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>x>>y>>x2>>y2;
    if(x==x2)
    {
        if(y==y2)cout<<"coincide";
        else cout<<"parallel";
    }
    else {cout<<"intersect\n";
        double l=((double)y-(double)y2)/((double)x2-(double)x);
        double r=(double)x*(double)l+(double)y;
        cout<<fixed<<setprecision(16)<<l<<' '<<r;
    }




}

