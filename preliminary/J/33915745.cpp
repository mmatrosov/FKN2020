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

void entry_point([[maybe_unused]] int test_id) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> id(n, vector<int>(m));
    int rem_cells = n * m;
    int i = 0;
    int son;
    for (son = 0; rem_cells > 0; son++) {
        int cnt = son + 1;
        if ((rem_cells - cnt) <= cnt) {
            cnt = rem_cells;
        }
        // $ printf("son #%d: has %d cells\n", son, cnt);
        rem_cells -= cnt;
        for (int j = 0; j < cnt; ++i, ++j) {
            int row_id = 2 * (i / (2 * m));
            int off = i % (2 * m);
            int col_id;
            if (off < m) {
                col_id = off;
            } else {
                col_id = (m - 1) - (off - m);
                ++row_id;
            }
            id[row_id][col_id] = son;
        }
    }
    $ {
        for (auto row : id) {
            for (auto cell : row) {
                printf("%d ", cell);
            }
            printf("\n");
        }
        printf("\n");
    }
    // printf("son count: %d\n", son);

    vector<vector<int>> g(son);
    for (int i1 = 0; i1 < n; ++i1) {
        for (int j1 = 0; j1 < m; ++j1) {
            int const dx[4] = {1, -1, 0, 0};
            int const dy[4] = {0, 0, 1, -1};
            for (int k = 0; k < 4; ++k) {
                int const i2 = i1 + dx[k];
                int const j2 = j1 + dy[k];
                if (i2 < 0 || j2 < 0 || i2 >= n || j2 >= m) {
                    continue;
                }
                int u = id[i1][j1];
                int v = id[i2][j2];
                if (u == v) {
                    continue;
                }
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    }
    vector<char> color(son);
    set<int> wait;
    for (int s = 0; s < son; ++s) {
        wait.insert(s);
    }
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        if (wait.empty()) {
            break;
        }
        //$ printf("painting into %c\n", ch);
        set<int> poss = wait;
        set<int> nwait;
        for (int s : wait) {
            if (!poss.count(s)) {
                nwait.insert(s);
                continue;
            }
            //$ printf("paint %d\n", s);
            color[s] = ch;
            for (auto ss : g[s]) {
                poss.erase(ss);
            }
        }

        wait = nwait;
    }
    printf("%d\n", son);
    for (auto row : id) {
        for (auto cell : row) {
            printf("%c", color[cell]);
        }
        printf("\n");
    }
    printf("\n");
}