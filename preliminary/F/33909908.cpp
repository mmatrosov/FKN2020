/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

                                         /*..         ....
                                    ..',,'..............''...'''.','..
                                  .';'..                          ..',,'.
                                 .'..                                 .';,.
                                .'.              .:ol;.                 .';.
                                ..              .cO00k:.                  .,.
                               ..          .'...;k00Od'                   .'.
                              ...        .;xOkxdk00Od,                    ...
                             ...        .,x0000000Od;.                     ..
                             .'         .cO00OOOOOOd;'...                 ...
                            .'.          .;lxkOOOO00Okkxo:.               .'.
                           .'.             .cxOOOOO000000Ol.              .'.
                          .'.             .ck00OOd::oxOOOOl.              .,.
                          ''...,;''''''''':kKK0Od,. ..:xOo'               .,.
                         ';,;;;:,..........;lxOx:.    .';'               .''
                        'cc;..               .,;:,..                     ...
                       ,oc.       ..........    .',:;,..                 ...
                      'o:.     .,;;;,,,,;;;;;'.    ..,;;,..              ...
                      ';.      ...         .,::.       .,::'.            .'.
                      ..                     .',.        ..;;'.         ...
                     ..          .',,;;,'.                  ':;'.       .,.
                    .,::;,.        .......                   .';:'.    .,,.
                    .;dOK0x;.                         .        .':;.   .,.
                    ...,cdxdl;.              ..,;;;cloddoc;.     .,:,. .,.
                   .     ...;cl:.          ':ldxxdocccclol;.      ..:;.',.
                   .   .;llc;',c;.       .,:,''';::;'.  ..          .;:;'
                      .:xdoxko,',.      .,:. .;llc:ldl.              .;c.
                      .lxdoxkd:''.     .;:.  .cxl'';od;.          .. .,,
                      .:clool;.',.     .:'   .:dxolccl;.         .::;,:'
                       .;::,.. .,.     .;.   .,:;:;,,;'         .,;,:ol.
                         ..    ',.     .;.    .',,,,,.          .,:llc;.
                              .,'      .,.                      .;lxxc'
                             .,;.      .;.                      .;lxxc.
            ..              .;;.       .:'                      .;cc,.
           ...';'          .;;.        .;:.                      ,:'
          .;c:;.       .. .,;.       ....,;.                     .'.
         .,lc,.      .':,..,:,''....;c:;'':'..              ..   .'.
         .;:;.      .,:'   .::,,;;;;;..',;,..,,.            .,.  .'.
        .'',,.     .,;.                      .;,            .'.  ...
        .'',,.    .,;.                        ';.           .,.  .'.
        .'...     .;.                         .,,.          .,'   ..
        .'.      .;,.                          .::.         .,'   .
        .'.     .,;.                            ,c'         .,'  .'.
        .'.     .:'                             .,'          .. .,'
         ''.    ,;.    .....................    .;'            .:,
         .,.   .,;.   ..'''''''''''''''''','.  .,;.           .::.
          .,.   ,;.                           .,;.           .;,.
          .,,.  .:,.                         .;;.          .''.
           .,'   .'.                         ...          .,.
            .''                                          .,.
             .,'.                                       .'.
              .'.                                      .*/

#include <fstream>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <set>
#include <map>

#define int long long
#define ld long double
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define eb emplace_back
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define all(v) v.begin(), v.end()
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("unroll-loops")

using namespace std;

template<typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
    _out << _p.first << ' ' << _p.second;
    return _out;
}

template<typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
    _in >> _p.first >> _p.second;
    return _in;
}

template<typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
    if (_v.empty()) { return _out; }
    _out << _v.front();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}

template<typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
    for (auto &_i : _v) { _in >> _i; }
    return _in;
}

const int MAXN = 3e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

class tarifplans {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, k;
        in >> n >> k;
        vc<int> a(n);
        in >> a;
        sort(all(a));
        vc<vc<pr<int, int>>> dp(k + 1, vc<pr<int, int>>(n + 1, {0, 0}));
        for (int l = 0; l < k; l++) {
            for (int i = 0; i < n; i++) {
                for (int x = i; x < n; x++) {
                    dp[l + 1][x + 1] = max(dp[l + 1][x + 1], {dp[l][i].fs + (x - i + 1) * a[i], i});
                }
            }
            for (int i = 0; i < n; i++) {
                dp[l + 1][i + 1] = max(dp[l + 1][i + 1], dp[l + 1][i]);
            }
        }
        vc<int> ans;
        int pos = n;
        for (int l = k; l >= 1; l--) {
            auto x = dp[l][pos];
            ans.pb(a[x.sc]);
            pos = x.sc;
            if (pos == 0) {
                break;
            }
        }
        while(ans.back() == 0){
            ans.ppb();
        }
        if (len(ans) == 0){
            ans.pb(1);
        }
        reverse(all(ans));
        while(len(ans) < k){
            ans.pb(ans.back() + 1);
        }
        out << ans;
    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	tarifplans solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
