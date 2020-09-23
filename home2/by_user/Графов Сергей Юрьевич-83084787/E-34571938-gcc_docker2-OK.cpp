#include<iostream>
#include<map>
#include<string>
#include<tuple>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, std::tuple<int64_t, int64_t>> marks;
    std::string name;
    int64_t mark;
    for (int i = 0; i < n; ++i) {
        std::cin >> name >> mark;
        std::get<0>(marks[name]) += mark;
        ++std::get<1>(marks[name]);
        std::cout << std::get<0>(marks[name]) / std::get<1>(marks[name]) << "\n";
    }
}
