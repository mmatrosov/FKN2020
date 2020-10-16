#include <iostream>
#include <string>

class Serializer {
public:
    Serializer() {
    }
    virtual void BeginArray() {
    }
    virtual void AddArrayItem(const std::string& s) {
    }
    virtual void EndArray() {
    }
    virtual ~Serializer() {
    }
};

class JsonSerializer : public Serializer {
private:
    bool begin = false;
    int cnt = 0;

public:
    void BeginArray() override {
        if (begin || cnt == 0) {
            begin = true;
            std::cout << "[";
            cnt += 1;
        } else {
            std::cout << ",";
            begin = true;
            std::cout << "[";
            cnt += 1;
        }
    }
    void AddArrayItem(const std::string& s) override {
        if (begin) {
            std::cout << "\"" << s << "\"";
            begin = false;
        } else {
            if (cnt > 0) {
                std::cout << ",";
                std::cout << "\"" << s << "\"";
                begin = false;
            }
        }
    }
    void EndArray() override {
        std::cout << "]";
        begin = false;
        cnt -= 1;
    }

    ~JsonSerializer() override {
    }
};
