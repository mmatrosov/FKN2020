#include "writer.h"

class BufferedWriter : public Writer {
    size_t mxbuf, cur;
    char* buffer;

public:
    BufferedWriter(size_t mxbuf0) : mxbuf(mxbuf0), cur(0) {
        buffer = new char[mxbuf];
    }

    void Write(const char* data, size_t len) override {
        for (size_t i = 0; i < len; ++i) {
            buffer[cur++] = data[i];
            if (cur == mxbuf) {
                cur = 0;
                Writer::Write(buffer, mxbuf);
            }
        }
    }

    ~BufferedWriter() {
        if (cur) {
            Writer::Write(buffer, cur);
        }
        delete[] buffer;
    }
};