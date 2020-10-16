Matrix(const Matrix<T>& other) {
    rows = other.rows;
    columns = other.columns;
    data = new T * [rows];
    size_t i = 0;
    try {
        for (; i != rows; ++i) {
            data[i] = new T[columns];
            for (size_t j = 0; j != columns; ++j)
                data[i][j] = other.data[i][j];
        }
    } catch (...) {
        for (size_t k = 0; k != i; ++k)
            delete [] data[k];
        delete [] data;
        throw;
    }
}

Matrix<T>& operator=(const Matrix<T>& other) {
    delete [] data;
    rows = other.rows;
    columns = other.columns;
    size_t i = 0;
    try {
        data = new T* [rows];
        for (; i != rows; ++i) {
            data[i] = new T[columns];
            for (size_t j = 0; j != columns; ++j)
                data[i][j] = other.data[i][j];
        }
    } catch (...) {
        for (size_t k = 0; k != i; ++k)
            delete [] data[k];
        delete [] data;
        throw;
    }
    return *this;
}