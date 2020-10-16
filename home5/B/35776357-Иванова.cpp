Matrix(Matrix const& other): Matrix(other.rows, other.columns) {
    for (size_t i = 0; i != rows; ++i)
        for (size_t j = 0; j != columns; ++j)
            data[i][j] = other.data[i][j];
}

Matrix& operator=(Matrix&& other) {
    std::swap(rows, other.rows);
    std::swap(columns, other.columns);
    std::swap(data, other.data);
    return *this;
}
