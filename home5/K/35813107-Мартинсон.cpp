#include <iostream>
#include <string>
#include <vector>

#include "writer.h"

class BufferedWriter : public Writer {
private:
    size_t size;
    std::vector<char> buf;
    size_t ind = 0;

public:
    BufferedWriter(size_t new_size) : size(new_size) {
    }

    void Write(const char* data, size_t len) override {
        for (size_t i = 0; i < len; ++i) {
            if (ind == size) {
                Writer::Write(&(buf[0]), size);
                buf.clear();
                ind = 0;
            }
            buf.push_back(*(data + i));
            ++ind;
        }
    }
    ~BufferedWriter() {
        Writer::Write(&(buf[0]), ind);
        // Writer.Write(bif, ind);
    }
};
