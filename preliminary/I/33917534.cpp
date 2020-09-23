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
#define FAST_ALLOCATOR_MEMORY 216 * 1024 * 1024
#if defined(FAST_ALLOCATOR_MEMORY) && !defined(_WIN32)
int allocator_pos = 0;
char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];

inline int likely_is(int x, int exp) {
#ifdef __GNUC__
    return (int)__builtin_expect(x, exp);
#endif
    return x;
}

inline void *operator new(size_t n) {
    char *res = allocator_memory + allocator_pos;
    allocator_pos += (int)n;
    int diff = allocator_pos - (int)FAST_ALLOCATOR_MEMORY;
    int is_mem_exceeded = diff > 0 ? 1 : 0;

    if (likely_is(is_mem_exceeded, 0)) {
        for (int i = 0; i < 1e9; ++i) {
            auto buf = (char *)malloc(4096);
            buf[7] = buf[228] = buf[1337] = '#';
            buf[0] = buf[4095] = '$';
        }
    }
    return (void *)res;
}

inline void operator delete(void *) noexcept {}

inline void operator delete(void *, size_t) {}
// inline void * operator new [] ( size_t ) { assert(0); }
// inline void operator delete [] ( void * ) { assert(0); }
#endif
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
vector<vector<pair<int, ll>>> g;
vector<ll> dijkstra(vector<int> seed) {
    vector<ll> dist(n, LLONG_MAX);
    priority_queue<pair<ll, int>> q;
    for (int v : seed) {
        dist[v] = 0;
        q.emplace(0, v);
    }
    while (!q.empty()) {
        auto [d, v] = q.top();
        d = -d;
        q.pop();
        if (d != dist[v]) {
            continue;
        }
        for (auto [w, edge] : g[v]) {
            if (dist[w] > d + edge) {
                dist[w] = d + edge;
                q.emplace(-dist[w], w);
            }
        }
    }

    return dist;
}

void entry_point([[maybe_unused]] int test_id) {
    int m, k;
    cin >> n >> m >> k;
    vector<int> fire(k);
    for (int &f : fire) {
        cin >> f;
        --f;
    }
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int s, f;
    cin >> s >> f;
    --s;
    --f;
    auto escape = dijkstra({s});
    auto die = dijkstra(fire);
    ll ans = escape[f];
    if (escape[f] >= die[f]) {
        ans = -1;
    }
    cout << ans << endl;
}