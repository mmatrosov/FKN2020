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

class Date {
 private:
    int d, m, y;

 public:
    Date(int _d, int _m, int _y) {
        if (_d < 1 || _m < 1 || _m > 12 || _y < 1970 || _y > 2099 ||
            !check(_y) && days[_m - 1] < _d || check(_y) && daysv[_m - 1] < _d) {
            throw std::invalid_argument("Bad Date");
        }
        d = _d;
        m = _m;
        y = _y;
    }

    const int GetDay() const {
        return d;
    }

    const int GetMonth() const {
        return m;
    }

    const int GetYear() const {
        return y;
    }

    Date& operator++() {
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
        return *this;
    }

    Date& operator--() {
        if (d == 1) {
            if (m == 1) {
                d = 31;
                m = 12;
                --y;
            } else if (check(y)) {
                d = daysv[m - 2];
                --m;
            } else {
                d = days[m - 2];
                --m;
            }
        } else {
            --d;
        }
        return *this;
    }

    Date& operator+ (int ds) {
        if (ds > 0) {
            while (ds) {
                --ds;
                ++(*this);
            }
        } else {
            while (ds < 0) {
                ++ds;
                --(*this);
            }
        }
        return *this;
    }

    Date& operator- (int ds) {
        if (ds > 0) {
            while (ds) {
                --ds;
                --(*this);
            }
        } else {
            while (ds < 0) {
                ++ds;
                ++(*this);
            }
        }
        return *this;
    }

    bool operator< (const Date& a) {
        return std::make_tuple(a.y, a.m, a.d) > std::make_tuple(y, m, d);
    }

    bool operator> (const Date& a) {
        return std::make_tuple(a.y, a.m, a.d) < std::make_tuple(y, m, d);
    }

    int operator-(const Date& a) {
        Date td = Date(d, m, y);
        int ans = 0;
        while (td < a) {
            ++td;
            --ans;
        }
        while (td > a) {
            --td;
            ++ans;
        }
        return ans;
    }
};