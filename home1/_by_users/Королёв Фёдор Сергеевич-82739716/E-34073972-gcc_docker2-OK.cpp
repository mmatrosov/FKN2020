#include <iostream>
#include <string>

int main() {
    std::string s;
    getline(std::cin, s);
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        int val = static_cast<int> (s[i]);
        ans += 1;
        if (val < 0) {
            val = 128 + val;
            int maxst = 64, cnt = 0;
            while (val >= maxst) {
                val -= maxst;
                maxst /= 2;
                cnt += 1;
            }
            i += cnt;
        }
    }
    std::cout << ans;
    return 0;
}
