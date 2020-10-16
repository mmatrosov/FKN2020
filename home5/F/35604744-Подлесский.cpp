#include <iostream>
#include <string>
#include <vector>

class Serializer {
protected:
    std::vector<bool> is_begin = {true};

public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string&) = 0;
    virtual void EndArray() = 0;
    virtual ~Serializer() {
    }
};

class JsonSerializer : public Serializer {
public:
    void BeginArray() {
        if (!is_begin.back())
            std::cout << ',';
        std::cout << "[";
        is_begin.back() = false;
        is_begin.push_back(true);
    }

    void EndArray() {
        is_begin.pop_back();
        std::cout << "]";
    }

    void AddArrayItem(const std::string& s) {
        if (!is_begin.back())
            std::cout << ',';
        std::cout << '"' << s << '"';
        is_begin.back() = false;
    }

    ~JsonSerializer() {
    }
};
