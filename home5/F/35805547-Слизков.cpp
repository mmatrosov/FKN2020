#include <cassert>
#include <iostream>
#include <stack>
#include <string>

class Serializer {
public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string&) = 0;
    virtual void EndArray() = 0;
    virtual ~Serializer() = default;
};

class JsonSerializer : public Serializer {  // making them all private
    std::stack<bool> nestedArrayHasFirstElementWritten;

public:
    void BeginArray() override {  // wow, BeginArray is now public
        if (!nestedArrayHasFirstElementWritten.empty() && nestedArrayHasFirstElementWritten.top())
            std::cout << ',';
        if (!nestedArrayHasFirstElementWritten.empty())
            nestedArrayHasFirstElementWritten.top() = true;
        std::cout << '[';
        nestedArrayHasFirstElementWritten.push(0);
    }
    void AddArrayItem(const std::string& item) override {
        assert(!nestedArrayHasFirstElementWritten.empty());
        if (nestedArrayHasFirstElementWritten.top())
            std::cout << ',';
        nestedArrayHasFirstElementWritten.top() = true;
        std::cout << "\"" << item << "\"";
    }
    void EndArray() override {
        std::cout << ']';
        nestedArrayHasFirstElementWritten.pop();
    }
    ~JsonSerializer() = default;
};
