#include <iostream>
#include <map>
#include <string>

int main() {
    int marks;
    std::cin >> marks;
    std::map<std::string, int64_t> sumMarks;
    std::map<std::string, int> marksCount;
    for (int i = 0; i < marks; ++i) {
        std::string name;
        std::cin >> name;
        int curMark;
        std::cin >> curMark;
        ++marksCount[name];
        sumMarks[name] += curMark;
        std::cout << sumMarks[name] / marksCount[name] << "\n";
    }
}
