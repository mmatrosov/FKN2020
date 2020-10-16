Matrix& operator=(Matrix&& other) {
    for (size_t i = 0; i != rows; ++i)
        delete[] data[i];
    delete[] data;

    rows = other.rows;
    columns = other.columns;
    data = other.data;
    other.rows = 0;
    other.columns = 0;
    other.data = nullptr;
    return *this;
}

Matrix(Matrix&& other) {
    data = new int*[0];
    rows = 0;
    columns = 0;
    *this = std::move(other);
}
