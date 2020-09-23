#include <string>
#include <vector>

std::string common_prefix(const std::string& a, const std::string& b) {
    size_t i = 0;
    while (i != a.size() && i != b.size() && a[i] == b[i])
        ++i;
    return a.substr(0, i);
}

std::string common_prefix(const std::vector<std::string>& words) {
    if (words.empty())
        return {};
    auto prefix = words[0];
    for (size_t i = 1; i != words.size() && !prefix.empty(); ++i)
        prefix = common_prefix(prefix, words[i]);
    return prefix;
}
