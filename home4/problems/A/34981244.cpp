#include <cmath>

class Complex {
   private:
    double real, imag;

   public:
    Complex(double _real = 0, double _imag = 0) {
        real = _real;
        imag = _imag;
    }

    double Re() const {
        return real;
    }

    double Im() const {
        return imag;
    }
};

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.Re() + b.Re(), a.Im() + b.Im());
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.Re() - b.Re(), a.Im() - b.Im());
}

Complex operator*(const Complex& a, const Complex& b) {
    return Complex(a.Re() * b.Re() - a.Im() * b.Im(), a.Re() * b.Im() + a.Im() * b.Re());
}

Complex operator/(const Complex& a, const Complex& b) {
    return Complex((a.Re() * b.Re() + a.Im() * b.Im()) / (b.Re() * b.Re() + b.Im() * b.Im()),
                   (a.Im() * b.Re() - a.Re() * b.Im()) / (b.Re() * b.Re() + b.Im() * b.Im()));
}

Complex operator+(const Complex& a) {
    return Complex(a.Re(), a.Im());
}

Complex operator-(const Complex& a) {
    return Complex(-a.Re(), -a.Im());
}

bool operator!=(const Complex& a, const Complex& b) {
    return a.Re() != b.Re() || a.Im() != b.Im();
}

bool operator==(const Complex& a, const Complex& b) {
    return a.Re() == b.Re() && a.Im() == b.Im();
}

double abs(const Complex& a) {
    return sqrt(a.Re() * a.Re() + a.Im() * a.Im());
}