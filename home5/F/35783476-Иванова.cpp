#include <iostream>
#include <string>
#include <vector>

class Serializer {
protected:
    std::vector<bool> is_begin;

public:
    virtual void BeginArray() {}

    virtual void AddArrayItem(const std::string &) {}

    virtual void EndArray() {}

    virtual ~Serializer() {}
};

class JsonSerializer: public Serializer {
public:
    void BeginArray() override {
        if (!is_begin.empty() && !is_begin.back())
            std::cout << ",";
        is_begin.push_back(true);
        std::cout << "[";
    }

    void AddArrayItem(const std::string& s) override {
        if (!is_begin.empty() && !is_begin.back())
            std::cout << ",";
        std::cout << "\"" << s << "\"";
        if (!is_begin.empty())
            is_begin.back() = false;
    }

    void EndArray() override {
        std::cout << "]";
        is_begin.pop_back();
        if (!is_begin.empty())
            is_begin.back() = false;
    }
};