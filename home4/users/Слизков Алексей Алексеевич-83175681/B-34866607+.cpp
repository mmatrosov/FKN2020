#include <iostream>

// oh...

class Rational {
    template <typename T, typename U>
    friend bool operator!=(const T& first, const U& second) {
        return !(first == second);
    }

    template <typename T, typename U>
    friend T& operator+=(T& first, const U& second) {
        return first = first + second;
    }
    template <typename T, typename U>
    friend T& operator-=(T& first, const U& second) {
        return first = first - second;
    }
    template <typename T, typename U>
    friend T& operator*=(T& first, const U& second) {
        return first = first * second;
    }
    template <typename T, typename U>
    friend T& operator/=(T& first, const U& second) {
        return first = first / second;
    }

    template <typename T>
    friend T operator++(T& _, int) {
        T temp(_);
        ++_;
        return temp;
    }
    template <typename T>
    friend T operator--(T& _, int) {
        T temp(_);
        --_;
        return temp;
    }
    /// you did not see this ^

    int _numerator = 0, _denominator = 1;

    static int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    void simplify() {
        int g = gcd(_numerator, _denominator);
        _numerator /= g, _denominator /= g;
        if (_denominator < 0)
            _numerator *= -1, _denominator *= -1;
    }
    static Rational simplify(Rational&& one) {
        one.simplify();
        return one;
    }
    static inline Rational simplify(int numerator, int denominator) {
        return simplify({numerator, denominator});
    }

   public:
    Rational() {
    }
    Rational(int a) : _numerator(a) {
    }
    Rational(int numerator, int denominator) : _numerator(numerator), _denominator(denominator) {
        simplify();
    }

    inline int numerator() const {
        return _numerator;
    }
    inline int denominator() const {
        return _denominator;
    }

    Rational operator+(const Rational& another) const {
        return simplify(_numerator * another._denominator + another._numerator * _denominator,
                        _denominator * another._denominator);
    }
    Rational operator+(int another) const {
        return simplify(_numerator + another * _denominator, _denominator);
    }
    friend Rational operator+(int first, const Rational& second) {
        return simplify(first * second._denominator + second._numerator, second._denominator);
    }
    Rational operator-(const Rational& another) const {
        return simplify(_numerator * another._denominator - another._numerator * _denominator,
                        _denominator * another._denominator);
    }
    Rational operator-(int another) const {
        return simplify(_numerator - another * _denominator, _denominator);
    }
    friend Rational operator-(int first, const Rational& second) {
        return simplify(first * second._denominator - second._numerator, second._denominator);
    }
    Rational operator*(const Rational& another) const {
        return simplify(_numerator * another._numerator, _denominator * another._denominator);
    }
    Rational operator*(int another) const {
        return simplify(_numerator * another, _denominator);
    }
    friend Rational operator*(int first, const Rational& second) {
        return simplify(first * second._numerator, second._denominator);
    }
    Rational operator/(const Rational& another) const {
        return simplify(_numerator * another._denominator, _denominator * another._numerator);
    }
    Rational operator/(int another) const {
        return simplify(_numerator, _denominator * another);
    }
    friend Rational operator/(int first, const Rational& second) {
        return simplify(first * second._denominator, second._numerator);
    }
    Rational operator+() const {
        return *this;
    }
    Rational operator-() const {
        return simplify(-_numerator, _denominator);
    }

    bool operator==(const Rational& another) const {
        return _numerator == another._numerator && _denominator == another._denominator;
    }
    bool operator==(int another) const {
        return _numerator == another && _denominator == 1;
    }
    friend bool operator==(int first, const Rational& second) {
        return first == second._numerator && second._denominator == 1;
    }

    Rational& operator++() {
        *this += 1;
        return *this;
    }
    Rational& operator--() {
        *this -= 1;
        return *this;
    }

    friend std::istream& operator>>(std::istream& in, Rational& object) {
        in >> object._numerator >> object._denominator;
        object.simplify();
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Rational& object) {
        out << object._numerator;
        if (object._denominator > 1)
            out << " / " << object._denominator;
        return out;
    }
};

/*#include <iomanip>

int main() {
    Rational a, b;
    std::cin >> a >> b;
    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << "\n\n";
    std::cout << std::boolalpha;
    std::cout << "operators of the form \"Rational @ Rational\":\n";
    std::cout << "\t(" << a << ") + (" << b << ") = " << a + b << '\n';
    std::cout << "\t(" << a << ") - (" << b << ") = " << a - b << '\n';
    std::cout << "\t(" << a << ") * (" << b << ") = " << a * b << '\n';
    std::cout << "\t(" << a << ") / (" << b << ") = " << a / b << '\n';
    std::cout << "\t" << a << " == " << b << ": " << (a == b) << '\n';
    std::cout << "\t" << a << " != " << b << ": " << (a != b) << '\n';
    std::cout << "operators of the form \"Rational @ int\":\n";
    std::cout << "\t(" << a << ") + " << b.numerator() << " = " << a + b.numerator() << '\n';
    std::cout << "\t(" << a << ") - " << b.numerator() << " = " << a - b.numerator() << '\n';
    std::cout << "\t(" << a << ") * " << b.numerator() << " = " << a * b.numerator() << '\n';
    std::cout << "\t(" << a << ") / " << b.numerator() << " = " << a / b.numerator() << '\n';
    std::cout << "\t" << a << " == " << b.numerator() << ": " << (a == b) << '\n';
    std::cout << "\t" << a << " != " << b.numerator() << ": " << (a != b) << '\n';
    std::cout << "operators of the form \"int @ Rational\":\n";
    std::cout << "\t" << a.numerator() << " + (" << b << ") = " << a.numerator() + b << '\n';
    std::cout << "\t" << a.numerator() << " - (" << b << ") = " << a.numerator() - b << '\n';
    std::cout << "\t" << a.numerator() << " * (" << b << ") = " << a.numerator() * b << '\n';
    std::cout << "\t" << a.numerator() << " / (" << b << ") = " << a.numerator() / b << '\n';
    std::cout << "\t" << a.numerator() << " == " << b << ": " << (a.numerator() == b) << '\n';
    std::cout << "\t" << a.numerator() << " != " << b << ": " << (a.numerator() != b) << '\n';
    std::cout << "operators of the form \"Rational @= Rational\":\n";
    std::cout << "\t\"a += b\" returns " << (a += b) << '\n';
    std::cout << "\t\"a -= b\" returns " << (a -= b) << '\n';
    std::cout << "\t\"a *= b\" returns " << (a *= b) << '\n';
    std::cout << "\t\"a /= b\" returns " << (a /= b) << '\n';
    std::cout << "operators of the form \"Rational @= int\":\n";
    std::cout << "\t\"a += " << b.numerator() << "\" returns " << (a += b.numerator()) << '\n';
    std::cout << "\t\"a -= " << b.numerator() << "\" returns " << (a -= b.numerator()) << '\n';
    std::cout << "\t\"a *= " << b.numerator() << "\" returns " << (a *= b.numerator()) << '\n';
    std::cout << "\t\"a /= " << b.numerator() << "\" returns " << (a /= b.numerator()) << '\n';
    std::cout << "operators of the forms \"@Rational\", \"Rational@\":\n";
    std::cout << "\t\"+a\" returns " << +a << '\n';
    std::cout << "\t\"-a\" returns " << -a << '\n';
    std::cout << "\t\"++a\" returns " << ++a << '\n';
    std::cout << "\t\"a++\" returns " << a++ << '\n';
    std::cout << "\t\"--a\" returns " << --a << '\n';
    std::cout << "\t\"a--\" returns " << a-- << '\n';
    std::cout << "\tfinally a = " << a << '\n';
}*/
