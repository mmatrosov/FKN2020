#include <iostream>
#include <string>

class Serializer {
protected:
    bool stringlast = false;
public:
    virtual void BeginArray() {}
    virtual void AddArrayItem(const std::string& s) {}
    virtual void EndArray() {}
};

class JsonSerializer : public Serializer {
public:
    virtual void BeginArray() {
        if (stringlast) {
            std::cout << ",";
            stringlast = false;
        }
        std::cout << "[";
    }
    virtual void AddArrayItem(const std::string& s) {
        if (stringlast) {
            std::cout << ",";
            stringlast = false;
        }
        std::cout << '"' <<  s << '"';
        stringlast = true;
    }
    virtual void EndArray() {
        std::cout << "]";
        stringlast = true;
    }
};