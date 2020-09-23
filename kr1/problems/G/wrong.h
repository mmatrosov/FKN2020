#include <map>
#include <string>
#include <vector>

using Dict = std::map<std::string, int>;

Dict final_standings(const std::vector<Dict>& dicts) {
    Dict result;
    for (const auto& dict : dicts) {
        for (const auto& [key, value] : dict) {
            if (value > result[key])
                result[key] = value;
        }
    }
    return result;
}
