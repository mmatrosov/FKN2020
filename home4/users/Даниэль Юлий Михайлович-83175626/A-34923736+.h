#include <math.h>

class Complex {
   private:
    double a = 0, b = 0;

   public:
    Complex(double a0) {
        a = a0, b = 0;
    }

    Complex(double a0, double b0) {  //
        a = a0, b = b0;
    }

    Complex(const Complex &other) {
        a = other.a, b = other.b;
    }

    double Re() const {
        return a;
    }

    double Im() const {
        return b;
    }

    bool operator==(const Complex &other) const {
        return a == other.a && b == other.b;
    }

    bool operator!=(const Complex &other) const {
        return !(*this == other);
    }

    void operator+=(const Complex &other) {
        a += other.a;
        b += other.b;
    }

    void operator-=(const Complex &other) {
        a -= other.a;
        b -= other.b;
    }

    Complex operator+(const Complex &other) const {
        Complex ans = *this;
        ans += other;
        return ans;
    }

    Complex operator-(const Complex &other) const {
        Complex ans = *this;
        ans -= other;
        return ans;
    }

    Complex operator-() const {
        return Complex(-a, -b);
    }

    Complex operator+() const {
        return Complex(a, b);
    }

    Complex operator*(const Complex &other) const {
        return Complex(a * other.a - b * other.b, a * other.b + b * other.a);
    }

    Complex operator*(const double &k) const {
        return Complex(a * k, b * k);
    }

    Complex operator/(const Complex &other) const {  //
        Complex ans = (*this) * Complex(other.a, -other.b);
        double mod = other.Re() * other.Re() + other.Im() * other.Im();
        ans.a /= mod, ans.b /= mod;
        return ans;
    }
};

Complex operator*(const double &k, const Complex &A) {
    return Complex(A.Re() * k, A.Im() * k);
}

double abs(const Complex &z) {
    return pow(z.Re() * z.Re() + z.Im() * z.Im(), 0.5);
}