#include <vector>
#include <utility>

template <typename T>
class Table {
 private:
    size_t n, m;
    std::vector <std::vector <T> > mat;

 public:
    Table(size_t _n, size_t _m) {
        n = _n;
        m = _m;
        mat.resize(n);
        for (int i = 0; i < n; ++i) {
            mat[i].resize(m);
        }
    }

    const std::vector <T>& operator[] (size_t x) const {
        return mat[x];
    }

    std::vector <T>& operator[] (size_t x) {
        return mat[x];
    }

    void resize(size_t nn, size_t nm) {
        mat.resize(nn);
        for (int i = 0; i < nn; ++i) {
            mat[i].resize(nm);
        }
        n = nn;
        m = nm;
    }

    const std::pair <size_t, size_t> size() const {
        return {n, m};
    }
};