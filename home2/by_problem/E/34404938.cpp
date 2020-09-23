#include <iostream>
#include <string>
#include <unordered_map>

struct StudentData {
    int64_t marks_count = 0;
    int64_t marks_sum = 0;

    int64_t average_mark() const {
        return marks_sum / marks_count;
    }
};

int main() {
    std::unordered_map<std::string, StudentData> students;
    int n;
    std::cin >> n;
    for (int _i = 0; _i < n; ++_i) {
        std::string student_name;
        int mark;
        std::cin >> student_name >> mark;
        auto& data = students[student_name];
        data.marks_count++;
        data.marks_sum += mark;
        std::cout << data.average_mark() << '\n';
    }
}