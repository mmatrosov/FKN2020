#include <iostream>
#include <string>

class Serializer {
   public:
    bool is_array_start = true;

    virtual void BeginArray() {
    }

    virtual void AddArrayItem(const std::string &) {
    }

    virtual void EndArray() {
    }
};

class JsonSerializer : public Serializer {
    void comma() {
        if (!is_array_start) {
            std::cout << ",";
        }
    }

   public:
    void BeginArray() {
        comma();
        std::cout << "[";
        is_array_start = true;
    }

    void AddArrayItem(const std::string &str) {
        comma();
        std::cout << '\"' << str << '\"';
        is_array_start = false;
    }

    void EndArray() {
        std::cout << "]";
        is_array_start = false;
    }
};
