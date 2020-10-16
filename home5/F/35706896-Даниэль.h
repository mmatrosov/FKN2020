#include <iostream>
#include <vector>

class Serializer {
public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string&) = 0;
    virtual void EndArray() = 0;
    virtual ~Serializer() {
    }
};

class JsonSerializer : public Serializer {
    std::vector<bool> begun = {0};

public:
    virtual void BeginArray() {
        if (begun.back())
            std::cout << ',';
        std::cout << '[';
        begun.push_back(false);
    }

    virtual void AddArrayItem(const std::string& elem) {
        if (begun.back())
            std::cout << ',';
        std::cout << '"' << elem << '"';
        begun.back() = true;
    }

    virtual void EndArray() {
        std::cout << ']';
        begun.pop_back();
        begun.back() = true;
    }

    ~JsonSerializer() {
    }
};