#include <iostream>
#include <set>

int main() {
    std::set<int> nums;
    int curNum;
    while (std::cin >> curNum) {
        std::cout << (nums.count(curNum) == 1 ? "YES" : "NO") << "\n";
        nums.emplace(curNum);
    }
}
