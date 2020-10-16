#include <iostream>
#include <string>

class Serializer {
 public:
    virtual void BeginArray() {}

    virtual void AddArrayItem(const std::string& s) {}

    virtual void EndArray() {}

    virtual ~Serializer() {}
};

class JsonSerializer : public Serializer {
 private:
    int cnt = 0;
    bool check = 0;

 public:
    virtual void BeginArray() {
        if (check)
            std::cout << ',';
        check = 0;
        std::cout << '[';
        ++cnt;
    }

    virtual void EndArray() {
        if (cnt == 0)
            return;
        std::cout << ']';
        --cnt;
        check = 1;
    }

    virtual void AddArrayItem(const std::string& s) {
        if (cnt == 0)
            return;
        if (check)
            std::cout << ',';
        check = 1;
        std::cout << '"' << s << '"';
    }

    virtual ~JsonSerializer() {}
};