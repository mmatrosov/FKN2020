#include <iostream>
#include <string>

class Serializer {
public:
    virtual void BeginArray() {}
    virtual void AddArrayItem(const std::string&) {}
    virtual void EndArray() {}
    virtual ~Serializer() {}
};

class JsonSerializer : public Serializer {
private:
    bool commaNeeded = false;;

public:
    void BeginArray() override {
        if (commaNeeded)
            std::cout << ',';
        std::cout << "[";
        commaNeeded = false;
    }
    void EndArray() override {
        std::cout << "]";
        commaNeeded = true;
    }
    void AddArrayItem(const std::string& word) override {
        if (commaNeeded)
            std::cout << ',';
        std::cout << "\"" << word << "\"";
        commaNeeded = true;
    }
    ~JsonSerializer() {}
};
