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

vector<pr<int, int>> g[MAXN];
int link[20 * MAXN][2];
int d[MAXN];
bool used[MAXN];
int last = 2;
int term[20 * MAXN];

void dfs(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to.fs]) {
            d[to.fs] = d[v] ^ to.sc;
            dfs(to.fs);
        }
    }
}

void add_string(int a, int i) {
    int v = 1;
    for (int x = 31; x >= 0; x--) {
        if (link[v][(a >> x) & 1] == 0) {
            link[v][(a >> x) & 1] = last++;
        }
        v = link[v][(a >> x) & 1];
    }
    term[v] = i;
}

pr<int, int> get_ans(int a) {
    int v = 1;
    int ans = 0;
    for (int x = 31; x >= 0; x--) {
        int b = ((a >> x) & 1) ^1;
        if (link[v][b] != 0) {
            v = link[v][b];
            ans |= (1ll << x);
        } else {
            v = link[v][b ^ 1];
        }
    }
    return {ans, term[v]};
}

class tovar {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        for (int i = 0; i < n - 1; i++) {
            int a, b, c;
            in >> a >> b >> c;
            a--, b--;
            g[a].pb({b, c});
            g[b].pb({a, c});
        }
        dfs(0);
        pr<pr<int, int>, int> ans = {{0, 0}, 0};
        for (int i = 0; i < n; i++) {
            add_string(d[i], i);
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, {get_ans(d[i]), i});
        }
        out << ans.fs.sc + 1 << ' ' << ans.sc + 1;
    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	tovar solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
