#include <cmath>

class Complex {
private:
    double real = 0, imag = 0;
public:
    Complex() {}

    Complex(double real) : real(real) {}

    Complex(double real, double imag) : real(real), imag(imag) {}

    double Re() const {
        return real;
    }

    double Im() const {
        return imag;
    }

    Complex Conj() const {
        return Complex(real, -imag);
    }
};

double dot(Complex first, Complex second) {
    return first.Re() * second.Re() - first.Im() * second.Im();
}

double abs(Complex cpl) {
    return sqrt(dot(cpl, cpl.Conj()));
}

bool operator==(Complex first, Complex second) {
    return (first.Re() == second.Re()) && (first.Im() == second.Im());
}

bool operator!=(Complex first, Complex second) {
    return !(first == second);
}

Complex operator-(Complex z) {
    return Complex(-z.Re(), -z.Im());
}

Complex operator+(Complex z) {
    return z;
}

Complex operator+(Complex first, Complex second) {
    return Complex(first.Re() + second.Re(), first.Im() + second.Im());
}

Complex operator-(Complex first, Complex second) {
    return first + (-second);
}

Complex operator*(Complex first, Complex second) {
    return Complex(
                   first.Re() * second.Re() - first.Im() * second.Im(),
                   first.Re() * second.Im() + first.Im() * second.Re());
}

Complex operator/(Complex first, Complex second) {
    return first * second.Conj() * (1 / dot(second, second.Conj()));
}