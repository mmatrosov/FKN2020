#include <cmath>
#include <iostream>
#include <map>

struct grade {
    long long sum;
    long long amount;
    grade() {
        sum = 0;
        amount = 0;
    }
    int get_average_grade() {
        return floor(static_cast<double>(sum) / static_cast<double>(amount));
    }
};

std::map <std::string, grade> journal;

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::string surname;
        long long mark;
        std::cin >> surname >> mark;
        journal[surname].amount++;
        journal[surname].sum += mark;
        std::cout << journal[surname].get_average_grade() << '\n';
    }
}
