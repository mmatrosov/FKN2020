#include <iostream>
#include <map>

struct mean {
    int64_t sum = 0;
    int count = 0;
};

int main() {
    std::map<std::string, mean> students;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::string name;
        int mark;
        std::cin >> name >> mark;
        mean &cur = students[name];
        ++cur.count;
        cur.sum += mark;
        std::cout << cur.sum / cur.count << '\n';
    }
    return 0;
}