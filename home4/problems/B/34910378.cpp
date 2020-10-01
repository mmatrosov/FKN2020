int my_gcd(int a, int b) {
    if (a < 0) {
        return my_gcd(-a, b);
    }
    if (b < 0) {
        return my_gcd(a, -b);
    }
    if (a < b) {
        return my_gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return my_gcd(b, a % b);
}

class Rational {
 private:
    int p, q;

 public:
    Rational(int _p = 0, int _q = 1) {
        p = _p;
        q = _q;
        p /= my_gcd(_p, _q);
        q /= my_gcd(_p, _q);
        if (q < 0) {
            q *= -1;
            p *= -1;
        }
    }

    int numerator() const {
        return p;
    }

    int denominator() const {
        return q;
    }

    inline bool operator==(const Rational& a) {
        return (a.numerator() == p && a.denominator() == q);
    }

    inline bool operator!=(const Rational& a) {
        return !((*this) == a);
    }

    Rational& operator=(const Rational& a) {
        p = a.numerator();
        q = a.denominator();
        return *this;
    }

    Rational operator+(const Rational& a) {
        Rational res = Rational(p * a.denominator() + q * a.numerator(), a.denominator() * q);
        return res;
    }

    Rational operator+(int a) {
        Rational res = Rational(p + q * a, q);
        return res;
    }

    Rational operator-(const Rational& a) {
        Rational res = Rational(p * a.denominator() - q * a.numerator(), a.denominator() * q);
        return res;
    }

    Rational operator-(int a) {
        Rational res = Rational(p - q * a, q);
        return res;
    }

    Rational operator*(const Rational& a) const {
        Rational res = Rational(p * a.numerator(), a.denominator() * q);
        return res;
    }

    Rational operator*(int a) const {
        Rational res = Rational(p * a, q);
        return res;
    }

    Rational operator/(const Rational& a) const {
        Rational res = Rational(p * a.denominator(), a.numerator() * q);
        return res;
    }

    Rational operator/(int a) {
        Rational res = Rational(p, q * a);
        return res;
    }

    Rational operator+() {
        Rational res = Rational(p, q);
        return res;
    }

    Rational operator-() {
        Rational res = Rational(-p, q);
        return res;
    }

    Rational operator+=(const Rational& a) {
        *this = (*this + a);
        return *this;
    }

    Rational operator-=(const Rational& a) {
        *this = (*this - a);
        return *this;
    }

    Rational operator*=(const Rational& a) {
        *this = (*this * a);
        return *this;
    }

    Rational operator/=(const Rational& a) {
        *this = (*this / a);
        return *this;
    }

    Rational operator+=(int a) {
        *this = (*this + a);
        return *this;
    }

    Rational operator-=(int a) {
        *this = (*this - a);
        return *this;
    }

    Rational operator*=(int a) {
        *this = (*this * a);
        return *this;
    }

    Rational operator/=(int a) {
        *this = (*this / a);
        return *this;
    }

    Rational& operator++() {
        *this = (*this + 1);
        return *this;
    }

    Rational operator++(int) {
        auto val = *this;
        *this = (*this + 1);
        return val;
    }

    Rational& operator--() {
        *this = (*this - 1);
        return *this;
    }

    Rational operator--(int) {
        *this = (*this - 1);
        return (*this + 1);
    }
};

Rational operator*(int a, const Rational& b) {
    Rational res = Rational(a * b.numerator(), b.denominator());
    return res;
}