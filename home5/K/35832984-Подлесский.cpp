#include "writer.h"

class BufferedWriter : public Writer {
private:
    char* buffer;
    size_t length;
    size_t cop = 0;

public:
    BufferedWriter(size_t len) : length(len) {
        buffer = new char[length];
    }
    void Write(const char* data, size_t len) override {
        size_t i = 0;
        while (i < len) {
            while (cop < length && i < len) {
                buffer[cop++] = data[i++];
            }
            if (cop == length) {
                Writer::Write(buffer, length);
                cop = 0;
            }
        }
    }
    ~BufferedWriter() {
        if (cop)
            Writer::Write(buffer, cop);
        delete[] buffer;
    }
};
