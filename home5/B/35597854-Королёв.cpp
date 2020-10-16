Matrix(const Matrix<T>& a) {
    rows = a.GetRows();
    columns = a.GetColumns();
    data = new T * [rows];
    size_t i = 0;
    try {
        for (; i != rows; ++i)
            data[i] = new T[columns];
    } catch (...) {
        for (size_t k = 0; k != i; ++k)
            delete [] data[k];
        delete [] data;
        throw;
    }
    for (size_t i = 0; i != rows; ++i)
        for (size_t j = 0; j != columns; ++j)
            data[i][j] = a[i][j];
}

void operator=(const Matrix<T>& a) {
    for (size_t i = 0; i != rows; ++i)
        delete [] data[i];
    delete [] data;
    rows = a.GetRows();
    columns = a.GetColumns();
    data = new T * [rows];
    size_t i = 0;
    try {
        for (; i != rows; ++i)
            data[i] = new T[columns];
    } catch (...) {
        for (size_t k = 0; k != i; ++k)
            delete [] data[k];
        delete [] data;
        throw;
    }
    for (size_t i = 0; i != rows; ++i)
        for (size_t j = 0; j != columns; ++j)
            data[i][j] = a[i][j];
}