#include "writer.h"

class BufferedWriter : public Writer {
private:
    size_t bufferSize, bufCount;
    char* buffer;

    void cleanBuffer() {
        Writer::Write(buffer, bufCount);
        bufCount = 0;
    }

public:
    BufferedWriter(size_t sz) : bufferSize(sz) {
        buffer = new char[sz];
        bufCount = 0;
    }

    void Write(const char * data, size_t len) override {
        for (size_t i = 0; i != len; ++i) {
            buffer[bufCount++] = data[i];
            if (bufCount == bufferSize)
                cleanBuffer();
        }
    }

    ~BufferedWriter() {
        cleanBuffer();
        delete [] buffer;
    }
};