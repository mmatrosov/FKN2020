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
#define rng(a) a.rbegin(),a.rend()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) (int)(a.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef long double ld;

const ld pi = 3.1415926535;


 
signed main(){
  ld a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << fixed << setprecision(10);
  ll r3 = a * a + b * b;
  ll r4 = c * c + d * d;
  ld r1 = sqrt(a * a + b * b);
  ld r2 = sqrt(c * c + d * d);
  if (r3 == 0 || r4 == 0){
    cout << r1 + r2;
    return 0;
  }
  if (r3 > r4){
    swap(a, c);
    swap(b, d);
    swap(r1, r2);
  }
  ld ans = r1 + r2;
  ld okr = 2 * r1;
  ld UGOL = (acos(max(ld(-1), min(ld(1), (a * c + b * d) / (r1 * r2)))));
  ans = min(ans, (r2 - r1) + min(UGOL, 6.283185307 - UGOL) * okr / ld(2));
  cout << ans;
}