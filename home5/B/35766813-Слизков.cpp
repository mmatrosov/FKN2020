Matrix(const Matrix& another) : Matrix(another.rows, another.columns) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            data[i][j] = another.data[i][j];
}

Matrix(Matrix&& another) {
    rows = another.rows, another.rows = 0;
    columns = another.columns, another.columns = 0;
    data = another.data, another.data = nullptr;
}

Matrix& operator=(Matrix&& another) {
    this->~Matrix();
    new (this) Matrix(another);
    return *this;
}
