#include <iostream>
#include <string>

int main() {
    std::string s;
    getline(std::cin, s);
    for (int i = 0; i < s.size(); i += 1) {
        int val = static_cast<int> (s[i]);
        if (val < 0) {
            val = 128 + val;
            int maxst = 64, cnt = 0, debaf = 0;
            while (val >= maxst) {
                val -= maxst;
                debaf += maxst;
                maxst /= 2;
                cnt += 1;
            }
            int sum = 0;
            for (int j = i; j <= i + cnt; j += 1) {
                sum *= 64;
                sum += (128 + static_cast<int> (s[j]));
                if (j == i) {
                    sum -= debaf;
                }
            }
            std::cout << sum << ' ';
            i += cnt;
            continue;
        }
        std::cout << val << ' ';
    }
    return 0;
}