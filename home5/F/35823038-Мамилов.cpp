#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Serializer {
public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string&) = 0;
    virtual void EndArray() = 0;

    virtual ~Serializer() {}
};

class JsonSerializer : public Serializer {
private:
    std::string data = "";
    std::stack<bool> isBlockFilled;

public:
    void BeginArray() {
        if (!isBlockFilled.empty() && isBlockFilled.top())
            data += ",";
        data += "[";
        isBlockFilled.push(false);
    }

    void AddArrayItem(const std::string& content) {
        if (isBlockFilled.top())
            data += ",";
        isBlockFilled.top() = true;
        data += "\"" + content + "\"";
    }

    void EndArray() {
        data += "]";
        isBlockFilled.pop();
        if (!isBlockFilled.empty())
            isBlockFilled.top() = true;
    }

    std::string GetJSON() {
        return data;
    }

    ~JsonSerializer() {
        std::cout << data;
    }
};