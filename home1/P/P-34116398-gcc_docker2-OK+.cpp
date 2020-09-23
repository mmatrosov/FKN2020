#include <iostream>
#include <vector>
#include <algorithm>

struct student {
    struct date {
        int day, month, year;
        bool operator< (const date& another) const {
            return year < another.year || year == another.year && month < another.month
                || year == another.year && month == another.month && day < another.day;
        }
        bool operator== (const date& another) const {
            return year == another.year && month == another.month && day == another.day;
        }
        friend std::istream& operator>> (std::istream& in, date& _) {
            in >> _.day >> _.month >> _.year;
            return in;
        }
        friend std::ostream& operator<< (std::ostream& out, const date& _) {
            out << _.day << '.' << _.month << '.' << _.year;
            return out;
        }
    } birth_date;

    struct anthroponym {
        std::string name, surname;
        bool operator< (const anthroponym& another) const {
            return surname < another.surname || surname == another.surname && name < another.name;
        }
        bool operator== (const anthroponym& another) const {
            return name == another.name && surname == another.surname;
        }
        friend std::istream& operator>> (std::istream& in, anthroponym& _) {
            in >> _.name >> _.surname;
            return in;
        }
        friend std::ostream& operator<< (std::ostream& out, const anthroponym& _) {
            out << _.name << ' ' << _.surname;
            return out;
        }
    } who;

    friend std::istream& operator>> (std::istream& in, student& Ivan) {
        in >> Ivan.who >> Ivan.birth_date;
        return in;
    }
    friend std::ostream& operator<< (std::ostream& out, const student& yet_another_one) {
        out << yet_another_one.who << ' ' << yet_another_one.birth_date;
        return out;
    }
};

struct comparator_type {
    enum comparison_order_type {date_first, anthroponym_first} comparison_order;
    comparator_type(const comparison_order_type& comparison_order) :
                    comparison_order(comparison_order) {}

    static bool comp_date(const student& first, const student& second) {
        return first.birth_date < second.birth_date
            || first.birth_date == second.birth_date && first.who < second.who;
    }
    static bool comp_anthroponym(const student& first, const student& second) {
        return first.who < second.who
            || first.who == second.who && first.birth_date < second.birth_date;
    }

    bool operator() (const student& first, const student& second) const {
        return comparison_order == date_first ? comp_date(first, second) :
                    comp_anthroponym(first, second);
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<student> students(n);
    for (int i = 0; i < n; ++i)
        std::cin >> students[i];
    std::string comp_type;
    std::cin >> comp_type;
    comparator_type comparator(comp_type == "date" ?
        comparator_type::date_first : comparator_type::anthroponym_first);
    std::sort(students.begin(), students.end(), comparator);
    for (const student& x : students)
        std::cout << x << '\n';
    return 0;
}
