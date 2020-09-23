//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC target("popcnt")
//#pragma GCC target("sse4")
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rng(a) a.begin(),a.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) (int)(a.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef long double ld;















signed main(){
    double k1,b1,k2,b2;
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2 && b1 == b2){
        cout << "coincide";
        return 0;
    }
    if (k1 == k2){
        cout << "parallel";
        return 0;
    }
    cout << "intersect" << endl;
    cout << fixed << setprecision(10);
    double X = (b2 - b1) / (k1 - k2);
    double Y = k1*X + b1;
    cout << X << ' ' << Y;  




}
