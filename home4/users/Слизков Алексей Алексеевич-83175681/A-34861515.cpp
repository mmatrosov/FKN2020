#include <cmath>
#include <iostream>

class Complex {
    static constexpr /* ? */ double eps = 1e-9;
    double real = 0, imag = 0;

   public:
    Complex() {
    }
    Complex(double real) : real(real) {
    }
    Complex(double real, double imag) : real(real), imag(imag) {
    }

    inline double Re() const {
        return real;
    }
    inline double Im() const {
        return imag;
    }

    Complex operator+(const Complex& another) const {
        return {real + another.real, imag + another.imag};
    }
    Complex operator+(double another) const {
        return {real + another, imag};
    }
    friend Complex operator+(double first, const Complex& second) {
        return {first + second.real, second.imag};
    }
    Complex operator-(const Complex& another) const {
        return {real - another.real, imag - another.imag};
    }
    Complex operator-(double another) const {
        return {real - another, imag};
    }
    friend Complex operator-(double first, const Complex& second) {
        return {first + second.real, second.imag};
    }
    Complex operator*(const Complex& another) const {
        return {real * another.real - imag * another.imag,
                real * another.imag + imag * another.real};
    }
    Complex operator*(double another) const {
        return {real * another, imag * another};
    }
    friend Complex operator*(double first, const Complex& second) {
        return {first * second.real, first * second.imag};
    }
    Complex operator/(const double& by) const {
        return {real / by, imag / by};
    }
    Complex operator/(const Complex& another) const {
        Complex conjugate(another.real, -another.imag);
        return *this * conjugate / (another.real * another.real + another.imag * another.imag);
    }
    friend Complex operator/(double first, const Complex& second) {
        return first / Complex(second);
    }
    Complex operator+() const {
        return *this;
    }
    Complex operator-() const {
        return {-real, -imag};
    }

    bool operator==(const Complex& another) const {
        return real == another.real && imag == another.imag;
    }
    bool operator==(double another) const {
        return real == another && fabs(imag) < eps;
    }
    friend bool operator==(double first, const Complex& second) {
        return first == second.real && fabs(second.imag) < eps;
    }
    bool operator!=(const Complex& another) const {
        return real != another.real || imag != another.real;
    }
    bool operator!=(double another) const {
        return real != another || fabs(imag) >= eps;
    }
    friend bool operator!=(double first, const Complex& second) {
        return first != second.real || fabs(second.imag) >= eps;
    }

    friend std::istream& operator>>(std::istream& in, Complex& me) {
        in >> me.real >> me.imag;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Complex& me) {
        out << me.real;
        if (fabs(me.imag) < 1e-9)
            return out;
        out << ' ' << (me.imag > 0 ? '+' : '-') << ' ' << fabs(me.imag) << 'i';
        return out;
    }
};

double abs(const Complex& one) {
    return sqrt(one.Re() * one.Re() + one.Im() * one.Im());
}

/*#include <iomanip>

int main() {
    Complex a, b;
    std::cin >> a >> b;
    std::cout << "(" << a << ") + (" << b << ") = " << a + b << '\n';
    std::cout << "(" << a << ") - (" << b << ") = " << a - b << '\n';
    std::cout << "(" << a << ") * (" << b << ") = " << a * b << '\n';
    std::cout << "(" << a << ") / (" << b << ") = " << a / b << '\n';
    std::cout << "+(" << a << ") = " << +a << '\n';
    std::cout << "-(" << a << ") = " << -a << '\n';
    std::cout << std::boolalpha;
    std::cout << a << " == " << b << ": " << (a == b) << '\n';
    std::cout << a << " != " << b << ": " << (a != b) << '\n';
    std::cout << "Re(" << a << ") = " << a.Re() << '\n';
    std::cout << "Im(" << a << ") = " << a.Im() << '\n';
    std::cout << "abs(" << a << ") = " << abs(a) << '\n';
    return 0;
}*/
