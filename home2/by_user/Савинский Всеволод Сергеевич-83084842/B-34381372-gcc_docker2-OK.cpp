#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<std::string> store;
    std::string rq, str;
    while (std::cin >> rq) {
        if (rq == "#") {
            return 0;
        }
        std::cin >> str;
        if (rq == "+") {
            store.insert(str);
        } else if (rq == "-") {
            if (store.find(str) != store.end()) {
                store.erase(store.find(str));
            }
        } else {
            std::cout << (store.find(str) != store.end() ? "YES" : "NO") << std::endl;
        }
    }
}
