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
string s,s2,s3[30000],ss;
char c[100100];


map<string,int>mp,mp2;

int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    cin>>s>>s2;
    bool f2=0;
    if(s[0]=='n')f=1;
    if(s2[0]=='y')f2=1;
    for(i=1;i<=n;i++)
    {
        cin>>s3[i];
        if(f)for(j=0;j<s3[i].size();j++)if(s3[i][j]>='A'&&s3[i][j]<='Z')s3[i][j]=s3[i][j]-'A'+'a';
    }
    int kol=0;
    while(cin>>s)
    {
        s+='%';
        s2=ss;
        for(i=0;i<s.size();i++)
        {kol++;
            if(s[i]>='A'&&s[i]<='Z')
            {
                if(f)s[i]=s[i]-'A'+'a';
                s2+=s[i];
            }
            else
            if(s[i]>='a'&&s[i]<='z')
            {
                s2+=s[i];
            }
            else
            if(s[i]>='0'&&s[i]<='9')
            {
                s2+=s[i];
            }
            else
            if(s[i]=='_')
            {
                s2+=s[i];
            }
            else
            {//cout<<s2<<endl;
                if((int)s2.size()>1||((int)s2.size()==1&&(s2[0]<'0'||s2[0]>'9')))
                {
                    bool fl=0;
                    if((!f2&&(s2[0]>='0'&&s2[0]<='9')))fl=1;
                    for(int j=1;j<=n;j++)if(s2==s3[j]){fl=1;break;}
                    if(!fl)
                    {
                        mp[s2]++;
                        if(mp2[s2]==0)mp2[s2]=kol;
                    }
                }
                s2=ss;
            }

        }
    }
    string sl=ss;
    ma=0;l=1e9;
    for(auto it:mp)
    {
        string x=it.first;
        int y=it.second;
        if(ma<y||(ma==y&&mp2[x]<l))ma=y,l=mp2[x],sl=x;
    }
    cout<<sl;

}


