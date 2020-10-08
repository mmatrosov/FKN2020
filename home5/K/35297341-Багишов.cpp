#include <cstring>
#include <vector>

#include "writer.h"

class BufferedWriter : public Writer {
    char* mBuf;  //
    size_t filled;
    size_t capacity;

    void Flush() {
        this->Writer::Write(mBuf, filled);
        filled = 0;
    }

public:
    BufferedWriter(size_t buffer_size)
        : mBuf(new char[buffer_size]), filled(0), capacity(buffer_size) {
    }

    void Write(char const* data, size_t len) override {
        while (len > 0) {  //
            size_t chunk_size = std::min(capacity - filled, len);
            if (chunk_size == 0) {
                Flush();
                continue;
            }
            std::memcpy(mBuf + filled, data, chunk_size);
            filled += chunk_size;
            data += chunk_size;
            len -= chunk_size;
        }
    }

    ~BufferedWriter() {
        Flush();
        delete[] mBuf;
    }
};
