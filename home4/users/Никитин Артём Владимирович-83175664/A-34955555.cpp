#include <cmath>

class Complex {
private:
    double real, imag;

public:
    Complex(double _real, double _imag) : real(_real), imag(_imag) { }
    Complex(double _real) : real(_real), imag(0) { }
    Complex operator+() const {
        return *this;
    }
    Complex operator-() const {
        return { -real, -imag };
    }
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator+(const double noncomplex) const {
        return *this + Complex(noncomplex, 0);
    }
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    Complex operator-(const double noncomplex) const {
        return *this - Complex(noncomplex, 0);
    }
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }
    Complex operator*(const double noncomplex) const {
        return *this * Complex(noncomplex, 0);
    }
    Complex operator/(const Complex& other) const {
        double denominator = (other.real * other.real + other.imag * other.imag);
        return Complex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }
    Complex operator/(const double noncomplex) {
        return *this / Complex(noncomplex, 0);
    }
    double Re() const {
        return real;
    }
    double Im() const {
        return imag;
    }
    double abs() const {
        return std::sqrt(real * real + imag * imag);
    }
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
};

Complex operator+(double x, const Complex& num) {
    return Complex(x) + num;
}

Complex operator-(double x, const Complex& num) {
    return Complex(x) - num;
}

Complex operator*(double x, const Complex& num) {
    return Complex(x) * num;
}

Complex operator/(double x, const Complex& num) {
    return Complex(x) / num;
}

double abs(Complex number) {
    return number.abs();
}
