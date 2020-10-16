#include <string>

#include "writer.h"

class BufferedWriter : public Writer {
    size_t bufsize;
    char *buf, *bufptr;

public:
    BufferedWriter(int bufsize) : bufsize(bufsize) {
        bufptr = buf = new char[bufsize];
    }

    void Write(const char* data, size_t len) override {
        while (len >= buf + bufsize - bufptr) {
            std::copy(data, data + (buf + bufsize - bufptr), bufptr);
            len -= buf + bufsize - bufptr, data += buf + bufsize - bufptr;
            Writer::Write(buf, bufsize), bufptr = buf;
        }
        std::copy(data, data + len, bufptr);
        bufptr += len;
    }

    ~BufferedWriter() {
        if (bufptr != buf)
            Writer::Write(buf, bufptr - buf);
        delete[] buf;
    }
};
