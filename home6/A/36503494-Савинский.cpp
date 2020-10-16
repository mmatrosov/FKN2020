#include <algorithm>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <vector>

struct Star {
    std::string name;
    uint64_t age;
};

std::string findStar(const std::vector<Star>& stars) {
    std::unordered_map<std::string, uint64_t> count;
    for (const auto& [name, age] : stars) {
        count[name] = std::max(count[name], age);
    }
    std::vector<uint64_t> ages;
    ages.reserve(count.size());
    for (const auto& [name, age] : count) {
        ages.push_back(age);
    }
    size_t mid = ages.size() / 2;
    std::nth_element(ages.begin(), ages.begin() + mid, ages.end());

    bool initialized = false;
    std::string_view res;
    for (const auto& [name, age] : count) {
        if (age == ages[mid] && (!initialized || name < res)) {
            initialized = true;
            res = name;
        }
    }
    return res.data();
}
