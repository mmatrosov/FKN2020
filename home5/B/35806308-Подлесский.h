Matrix(const Matrix& other) {
    rows = other.rows;
    columns = other.columns;
    data = new T*[rows];
    size_t i = 0;
    try {
        for (; i != rows; ++i)
            data[i] = new T[columns];
    } catch (...) {
        for (size_t k = 0; k != i; ++k)
            delete[] data[k];
        delete[] data;
        throw;
    }
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j)
            data[i][j] = other.data[i][j];
}

Matrix& operator=(Matrix&& other) {
    std::swap(rows, other.rows);
    std::swap(columns, other.columns);
    std::swap(data, other.data);
    return *this;
}
