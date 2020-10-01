#include <iostream>
#include <typeinfo>
#include <vector>

template <typename T>
class MathVector {
   private:
    std::vector<T> data;

   public:
    MathVector(size_t n) {
        // data = {};
        data.resize(n);
    }

    template <typename Iter>
    MathVector(Iter first, const Iter& last) {
        while (first != last) {
            data.push_back(*first);
            ++first;
        }
    }

    size_t Dimension() const {
        return data.size();
    }

    T& operator[](size_t i) {
        return data[i];
    }

    const T& operator[](size_t i) const {
        return data[i];
    }

    MathVector<T>& operator+=(const MathVector<T>& x) {
        for (size_t i = 0; i != this->Dimension(); ++i) {
            data[i] += x[i];
        }
        return *this;
    }
    friend MathVector<T> operator+(MathVector<T> x, const MathVector<T>& y) {
        return x += y;
    }

    MathVector<T>& operator*=(const T& scalar) {
        for (size_t i = 0; i != this->Dimension(); ++i)
            data[i] *= scalar;
        return *this;
    }

    friend MathVector<T> operator*(MathVector<T> v, const T& scalar) {
        return v *= scalar;
    }

    friend MathVector<T> operator*(const T& scalar, MathVector<T> v) {
        return v *= scalar;
    }
};
/*
template <typename T>
MathVector<T>& operator+=(MathVector<T>& v, const MathVector<T>& x) {
    for (size_t i = 0; i != v.Dimension(); ++i)
        v[i] += x[i];
    return v;
}

template <typename T>
MathVector<T> operator+(MathVector<T>& v, const MathVector<T>& x) {
    return v += x;
}

template <typename T>
MathVector<T>& operator*=(MathVector<T>& v, const T& scalar) {
    for (size_t i = 0; i != v.Dimension(); ++i)
        v[i] *= scalar;
    return v;
}

template <typename T>
MathVector<T> operator*(MathVector<T>& v, const T& scalar) {
    return v *= scalar;
}
// ???

template <typename T>
MathVector<T> operator*(const T& scalar, MathVector<T>& v) {
    return v *= scalar;
}
*/

// Output format: (1, 2, 3, 4, 5)
template <typename T>
std::ostream& operator<<(std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0) out << ", ";
        out << v[i];
    }
    out << ')';
    return out;
}
