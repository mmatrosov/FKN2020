#ifdef _DEV
#define DEV 1
#else
#define DEV 0
#pragma GCC optimize("O3")
#endif

#ifdef SELFHCECK_HEAVY
#define SELFCHECK_HEAVY 1
#define SELFCHECK 1
#endif

#ifdef SELFCHECK
#define SELFCHECK 1
#endif

#ifndef SELFCHECK
#define SELFCHECK 0
#endif
#ifndef SELFCHECK_HEAVY
#define SELFCHECK_HEAVY 0
#endif

#include <bits/stdc++.h>

#ifdef __GNUC__

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#endif
using namespace std;

void entry_point(int test_id);

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
// using xll = __int128;
using ld = long double;
using szt = size_t;

int main() {
    int num_cases = 1;
    if (DEV) {
        // num_cases = 100;
        // assert(freopen("./input.txt", "r", stdin));
    } else {
        const char *prob_name = "rendezvous";
        char out_file[100];
        char in_file[100];
        sprintf(out_file, "%s.out", prob_name);
        sprintf(in_file, "%s.in", prob_name);
        // freopen(in_file, "r", stdin);
        // freopen(out_file, "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    cout << fixed << setprecision(12);
    int it = 0;
    while (num_cases--) {
        entry_point(it++);
        fflush(stdout);
        fflush(stderr);
        bool ok = true;
        while (DEV) {
            int c = fgetc(stdin);
            if (c == EOF) {
                ok = false;
                break;
            }
            if (c >= 32) {
                ungetc(c, stdin);
                break;
            }
        }
        if (!ok) {
            break;
        }
    }
    return 0;
}

template <typename T> bool relmin(T &lhs, T const &rhs) {
    if (lhs > rhs) {
        lhs = rhs;
        return true;
    }
    return false;
}

template <typename T> bool relmax(T &lhs, T const &rhs) {
    if (lhs < rhs) {
        lhs = rhs;
        return true;
    }
    return false;
}

// who needs high-quality code?????
// [thinking](thinking.ascii)
#define $ if (DEV)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpl = complex<ld>;

#define BREAK __asm__ __volatile__("int3")

void checked_scanf(const char *fmt, ...) __attribute__((format(scanf, 1, 2)));

void checked_scanf(const char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    int const scan_res = vscanf(fmt, va);

    int cnt_percents = 0;
    while (*fmt) {
        if (*fmt++ == '%') {
            ++cnt_percents;
        }
    }
    if (cnt_percents != scan_res) {
        fprintf(
            stderr,
            "IO error: format string expected %d items, but actually got %d\n",
            cnt_percents, scan_res);
        abort();
    }

    va_end(va);
}

#if DEV || SELFCHECK_HEAVY
// Don't pay on production (~~write in Rust~~)
#define scanf checked_scanf
#endif

/*$__CODE_START__$*/

int n;
vector<vector<pair<int, uint>>> g;
vector<ll> acc;
void dfs(int v, uint cur_acc = 0) {
    //$ printf("dfs(%d, %lld)\n", v, cur_acc);
    acc[v] = cur_acc;
    for (auto [w, x] : g[v]) {
        if (acc[w] != LLONG_MAX) {
            continue;
        }
        dfs(w, cur_acc ^ x);
    }
}

struct Node {
    Node *go[2] = {0, 0};

    ~Node() {
        $ {
            delete go[0];
            delete go[1];
        }
    }
};

void entry_point([[maybe_unused]] int test_id) {
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        uint x;
        cin >> u >> v >> x;
        --u;
        --v;
        g[u].emplace_back(v, x);
        g[v].emplace_back(u, x);
    }
    acc.resize(n, LLONG_MAX);
    dfs(0);
    $ {
        printf("acc: ");
        for (auto x : acc) {
            printf("%lld ", x);
        }
        printf("\n");
    }

    map<uint, int> pos;
    for (int i = 0; i < n; ++i) {
        pos[(uint) acc[i]] = i;
    }
    int opt_i = 0;
    int opt_j = 0;
    Node *root = new Node;
    for (int i = 0; i < n; ++i) {
        ll x = acc[i];
        {
            Node *v = root;
            for (uint bit = 31; bit < 32; --bit) {
                int val = (x >> bit) & 1u;
                if (v->go[val] == nullptr) {
                    v->go[val] = new Node;
                }
                v = v->go[val];
            }
        }
        {
            uint ans = 0;
            Node const *v = root;
            for (uint bit = 31; bit < 32; --bit) {
                int val = (x >> bit) & 1u;
                if (v->go[1 - val]) {
                    val = 1 - val;
                }
                ans += (val << bit);
                v = v->go[val];
            }
            if ((acc[i] ^ ans) > (acc[opt_i] ^ acc[opt_j])) {
                opt_i = i;
                opt_j = pos[ans];
            }
        }
    }
    cout << opt_i + 1 << " " << opt_j + 1 << "\n";
    $ delete root;
}
