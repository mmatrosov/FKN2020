#include <vector>
#include <utility>

template <typename T>
class Table {
   private:
    std::vector<std::vector<T>> data;
    size_t rows, cols;

   public:
    Table(size_t rows0, size_t cols0) {
        rows = rows0, cols = cols0;
        data.resize(rows);
        for (auto& row : data)
            row.resize(cols);
    }

    const std::vector<T>& operator[](size_t i) const {
        return data[i];
    }

    std::vector<T>& operator[](size_t i) {
        return data[i];
    }

    void resize(size_t nrows, size_t ncols) {
        rows = nrows;
        cols = ncols;
        data.resize(rows);
        for (auto& row : data)
            row.resize(cols);
    }

    std::pair<int, int> size() const {
        return {rows, cols};
    }
};