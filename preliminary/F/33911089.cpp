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
    size_t n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) {
        cin >> x;
    }
    sort(all(a));
    vector<vector<pair<ll, int>>> dp(n + 1,
                                     vector<pair<ll, int>>(k + 1, {0, -1}));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < k; ++j) {
            for (size_t piv = 0; piv <= i; ++piv) {
                if (a[piv] == 0) {
                    continue;
                }
                ll res = a[piv] * (i - piv + 1) + dp[piv][j].first;
                relmax(dp[i + 1][j + 1], {res, piv});
            }
        }
    }
    cerr << "score: " << dp[n][k].first << endl;
    vector<ll> ans;
    size_t ci = n;
    size_t cj = k;
    while (true) {
        int piv = dp[ci][cj].second;
        if (piv == -1) {
            break;
        } else {
            --cj;
            ci = piv;
            ans.push_back(a[piv]);
        }
    }
    if (ans.size() == 0) {
        ans.push_back(444);
    }
    while (ans.size() < k) {
        ans.push_back(*max_element(all(ans)) + 1);
    }
    sort(all(ans));
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}