#include <iostream>
#include <cstddef>
#include "writer.h"

class BufferedWriter: public Writer {
private:
    size_t buffer_size = 0;
    char* data = nullptr;
    size_t pos = 0;

public:
    BufferedWriter(size_t sz): buffer_size(sz) {
        data = new char[sz];
    }

    void Write(const char * new_data, size_t len) override {
        for (size_t i = 0; i < len; ++i) {
            data[pos] = new_data[i];
            ++pos;
            if (pos == buffer_size) {
                Writer::Write(data, buffer_size);
                pos = 0;
            }
        }
    }

    ~BufferedWriter() {
        Writer::Write(data, pos);
        delete[] data;
    }
};