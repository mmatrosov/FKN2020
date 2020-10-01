#include <stdexcept>
#include <vector>
#include <tuple>
#include <iostream>

const std::vector <int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::vector <int> daysv = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(const int y) {
    if (y % 4) return 0;
    return 1;
}

std::tuple<int, int, int> upgrade(int d, int m, int y) {
    if (d == days[m - 1] && !check(y) || check(y) && d == daysv[m - 1]) {
        if (m == 12) {
            d = 1;
            m = 1;
            ++y;
        } else {
            d = 1;
            ++m;
        }
    } else {
        ++d;
    }
    return std::tie(d, m, y);
}

int mutate(int d, int m, int y) {
    int ans = 0;
    int td = 1, tm = 1, ty = 1970;
    while (td != d || tm != m || ty != y) {
        std::tie(td, tm, ty) = upgrade(td, tm, ty);
        ++ans;
    }
    return ans;
}

std::tuple<int, int, int> unmutate(int val) {
    int td = 1, tm = 1, ty = 1970;
    while (val) {
        --val;
        std::tie(td, tm, ty) = upgrade(td, tm, ty);
    }
    return std::tie(td, tm, ty);
}

class Date {
 private:
    int val;

 public:
    Date(int _d, int _m, int _y) {
        if (_d < 1 || _m < 1 || _m > 12 || _y < 1970 || _y > 2099 ||
            !check(_y) && days[_m - 1] < _d || check(_y) && daysv[_m - 1] < _d) {
            throw std::invalid_argument("Bad Date");
        }
        val = mutate(_d, _m, _y);
    }

    const int GetVal() const {
        return val;
    }

    const int GetDay() const {
        return std::get<0>(unmutate(val));
    }

    const int GetMonth() const {
        return std::get<1>(unmutate(val));
    }

    const int GetYear() const {
        return std::get<2>(unmutate(val));
    }

    Date& operator++() {
        ++val;
        return *this;
    }

    Date& operator--() {
        --val;
        return *this;
    }

    Date& operator+ (int ds) {
        val += ds;
        return *this;
    }

    Date& operator- (int ds) {
        val -= ds;
        return *this;
    }

    int operator-(const Date& a) {
        return val - a.GetVal();
    }
};