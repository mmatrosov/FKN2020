Matrix(Matrix& a) : Matrix(a.rows, a.columns) {
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j)
            data[i][j] = a[i][j];
    }
}
Matrix& operator=(Matrix&& a) {
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j)
            data[i][j] = a[i][j];
        }
    return (*this);
}
Matrix& operator=(Matrix& a) {
    Matrix b(a);
    *this = std::move(b);
    return (*this);
}