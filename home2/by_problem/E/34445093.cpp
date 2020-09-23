#include <unordered_map>
#include <iostream>
#include <string>

int main() {
    std::unordered_map<std::string, int64_t> sum, cnt;

    int n;
    std::cin >> n;
    while (n--) {
        std::string name;
        int grade;
        std::cin >> name >> grade;

        sum[name] += grade, cnt[name] += 1;
        std::cout << sum[name] / cnt[name] << std::endl;
    }
}
