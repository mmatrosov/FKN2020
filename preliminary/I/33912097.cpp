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
const int INF = 1e18;
const int MOD = 1e9 + 7;

vc<pr<int, int>> g[MAXN];

class spleiologi {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, m, k;
        in >> n >> m >> k;
        vector<int> infect(k);
        for (auto &v : infect) {
            in >> v;
            v--;
        }
        for (int i = 0; i < m; i++) {
            int a, b, c;
            in >> a >> b >> c;
            a--, b--;
            g[a].pb({b, c});
            g[b].pb({a, c});
        }
        int s, f;
        in >> s >> f;
        s--, f--;
        vector<int> d(n, INF);
        {
            set<pr<int, int>> q;
            for (auto v : infect) {
                d[v] = 0;
                q.insert({d[v], v});
            }
            while (len(q) > 0) {
                auto x = *q.begin();
                q.erase(q.begin());
                int v = x.sc;
                for (auto to : g[v]) {
                    if (d[to.fs] > d[v] + to.sc) {
                        q.erase({d[to.fs], to.fs});
                        d[to.fs] = d[v] + to.sc;
                        q.insert({d[to.fs], to.fs});
                    }
                }
            }
        }
        auto ds = d;
        d.assign(n, INF);
        {
            set<pr<int, int>> q;
            d[s] = 0;
            q.insert({d[s], s});
            while (len(q) > 0) {
                auto x = *q.begin();
                q.erase(q.begin());
                int v = x.sc;
                for (auto to : g[v]) {
                    if (d[to.fs] > d[v] + to.sc && d[v] + to.sc < ds[to.fs]) {
                        q.erase({d[to.fs], to.fs});
                        d[to.fs] = d[v] + to.sc;
                        q.insert({d[to.fs], to.fs});
                    }
                }
            }
        }
        if (d[f] >= INF){
            d[f] = -1;
        }
        out << d[f];
    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	spleiologi solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
