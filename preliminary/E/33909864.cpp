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

regex REGEX = regex("[a-zA-Z0-9_]+");

bool read_yes_no() {
    string buf;
    cin >> buf;
    $ assert(buf == "yes" || buf == "no");
    return buf[0] == 'y';
}

string strlow(string s) {
    string out;
    for (char ch : s) {
        if (isalpha(ch)) {
            ch = (char)tolower(ch);
        }
        out.push_back(ch);
    }
    return out;
}

struct UsageInfo {
    int first = -1;
    int count;
};

void entry_point([[maybe_unused]] int test_id) {
    $ printf("regex init ok\n");
    int cnt_keywords;
    cin >> cnt_keywords;
    bool const case_sensitive = read_yes_no();
    bool const ident_can_start_with_digit = read_yes_no();
    set<string> keywords;
    for (int i = 0; i < cnt_keywords; ++i) {
        string kw;
        cin >> kw;
        if (!case_sensitive) {
            kw = strlow(kw);
        }
        keywords.insert(kw);
    }
    map<string, UsageInfo> usages;

    $ printf("reading text\n");

    for (int token_cntr = 0;; token_cntr++) {
        string s;
        cin >> s;

        if (cin.eof() && s.size() == 0) {
            break;
        } else {
            //$ printf("processing token '%s'\n", s.c_str());
        }
        if (s.size() == 0) {
            continue;
        }
        if (!case_sensitive) {
            s = strlow(s);
        }

        regex_iterator<string::iterator> matches(all(s), REGEX), match_done;
        for (; matches != match_done; ++matches, ++token_cntr) {
            const auto &match_item = *matches;
            string match = match_item.str();
            $ printf("processing item %s\n", match.c_str());
            if (isdigit(match[0]) && !ident_can_start_with_digit) {
                //$ printf("starts with digit; skipping");
                continue;
            }
            bool has_only_digits = true;
            for (char ch : match) {
                if (!isdigit(ch)) {
                    has_only_digits = false;
                    break;
                }
            }
            if (has_only_digits) {
                $ printf("has only digits; skipping\n");
                continue;
            }
            if (keywords.count(match)) {
                continue;
                //$ printf("keyword; skipping");
            } //$ printf("ident");
            ++usages[match].count;
            if (usages[match].first == -1) {
                usages[match].first = token_cntr;
            }
        }
    }
    auto ans_item =
        *max_element(all(usages), [&](auto const &lhs, auto const &rhs) {
            UsageInfo const &inf_lhs = lhs.second;
            UsageInfo const &inf_rhs = rhs.second;
            if (inf_lhs.count != inf_rhs.count) {
                return inf_lhs.count < inf_rhs.count;
            }
            return inf_lhs.first > inf_rhs.first;
        });
    cout << ans_item.first << "\n";
}
