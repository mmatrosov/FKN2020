#include <cmath>

class Complex {
private:
    double re, im;
public:
    Complex() {
        re = im = 0.0;
    }
    Complex(double _re) {
        re = _re;
        im = 0.0;
    }
    Complex(double _re, double _im) {
        re = _re;
        im = _im;
    }
    double Re() const {
        return re;
    }
    double Im() const {
        return im;
    }
};

Complex operator+(Complex c, const Complex& other) {
    return Complex(c.Re() + other.Re(), c.Im() + other.Im());
}
Complex operator-(Complex c, const Complex& other) {
    return Complex(c.Re() - other.Re(), c.Im() - other.Im());
}
Complex operator*(Complex c, const Complex& other) {
    return Complex(
        c.Re() * other.Re() - c.Im() * other.Im(),
        c.Im() * other.Re() + c.Re() * other.Im());
}
Complex operator/(Complex c, const Complex& other) {
    return Complex(
        ((c.Re() * other.Re() + c.Im() * other.Im()) /
        (other.Re() * other.Re() + other.Im() * other.Im())),
        ((other.Re() * c.Im() - c.Re() * other.Im()) /
        (other.Re() * other.Re() + other.Im() * other.Im())));
}
Complex operator+(const Complex& c) {
    return Complex(c.Re(), c.Im());
}
Complex operator-(const Complex& c) {
    return Complex(-c.Re(), -c.Im());
}
bool operator==(const Complex& a, const Complex& b) {
    return a.Re() == b.Re() && a.Im() == b.Im();
}
bool operator!=(const Complex& a, const Complex& b) {
    return a.Re() != b.Re() || a.Im() != b.Im();
}
double abs(const Complex& c) {
    return std::sqrt(c.Re() * c.Re() + c.Im() * c.Im());
}
