#include <cstddef>
#include <vector>
#include "writer.h"

class BufferedWriter : public Writer {
    int iter;
    std::vector<char> buf;

    void flush() {
        Writer::Write(buf.data(), sizeof(buf.front()) * iter);
        iter = 0;
    }

   public:
    BufferedWriter(size_t sz) : iter(0), buf(sz) {
    }

    void Write(const char* data, size_t len) {
        for (size_t i = 0; i != len; ++i) {
            if (iter == buf.size()) {
                flush();
            }
            buf[iter++] = data[i];
        }
    }

    ~BufferedWriter() {
        flush();
    }
};
