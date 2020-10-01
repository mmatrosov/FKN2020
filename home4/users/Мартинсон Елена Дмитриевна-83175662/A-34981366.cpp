#include <cmath>
#include <iostream>

class Complex {
   private:
    double a;
    double b;

   public:
    Complex() {
        a = 0;
        b = 0;
    }

    Complex(double a1, double b1) {
        a = a1;
        b = b1;
    }
    Complex(double a1) {
        a = a1;
        b = 0;
    }
    double len() const {
        return a * a + b * b;
    }
    Complex operator+=(const Complex& x) {
        a += x.a;
        b += x.b;
        return *this;
    }
    Complex operator-=(const Complex& x) {
        a -= x.a;
        b -= x.b;
        return *this;
    }
    Complex operator*=(const Complex& x) {
        double c = a * x.a - b * x.b;
        b = b * x.a + a * x.b;
        a = c;
        return *this;
    }
    Complex operator/=(const Complex& x) {
        double res_a = a * x.a + b * x.b;
        double res_b = b * x.a - a * x.b;
        a = res_a / x.len();
        b = res_b / x.len();
        return *this;
    }

    friend Complex operator+(Complex x, const Complex& y) {
        return x += y;
    }
    friend Complex operator+(Complex x, const double d) {
        Complex c(d);
        return x += c;
    }
    friend Complex operator-(Complex x, const Complex& y) {
        return x -= y;
    }
    friend Complex operator-(Complex x, const double d) {
        Complex c(d);
        return x -= c;
    }
    friend Complex operator*(Complex x, const Complex& y) {
        return x *= y;
    }
    friend Complex operator*(Complex x, const double d) {
        return Complex(x.a * d, x.b * d);
    }
    friend Complex operator/(Complex x, const Complex& y) {
        return x /= y;
    }

    Complex operator-() const {
        return Complex(-a, -b);
    }
    Complex operator+() const {
        return *this;
    }
    double Re() const {
        return this->a;
    }
    double Im() const {
        return this->b;
    }
    friend bool operator==(const Complex& x, const Complex& y) {
        return x.a == y.a && x.b == y.b;
    }
    friend bool operator!=(const Complex& x, const Complex& y) {
        return x.a != y.a || x.b != y.b;
    }
    // void print() {
    //    std::cout << a << " " << b << "\n";
    // }
};

double abs(const Complex& a) {
    return sqrt(a.len());
}
