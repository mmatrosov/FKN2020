Matrix& operator=(Matrix&& tmp) {
    std::swap(data, tmp.data);
    std::swap(columns, tmp.columns);
    std::swap(rows, tmp.rows);

    return *this;
}
Matrix& operator=(Matrix const& that) {
    Matrix tmp = that;
    *this = std::move(tmp);
    return *this;
}
Matrix(Matrix const& that) : Matrix(that.rows, that.columns) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            data[i][j] = that.data[i][j];
        }
    }
}