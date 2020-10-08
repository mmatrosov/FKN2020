#include <iostream>
#include <string>
#include <vector>

class Serializer {
public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(std::string const&) = 0;
    virtual void EndArray() = 0;

    virtual ~Serializer() {
    }
};

struct State {
    bool empty = true;
};

class JsonSerializer : public Serializer {
    std::vector<State> mStates;

    void AddComma() {
        if (mStates.back().empty) {
            mStates.back().empty = false;
        } else {
            std::cout << ',';
        }
    }

public:
    void BeginArray() override {
        if (!mStates.empty()) {
            AddComma();
        }
        std::cout << '[';
        mStates.emplace_back();
    }
    void AddArrayItem(std::string const& item) override {
        AddComma();
        std::cout << '"' << item << '"';
    }
    void EndArray() override {
        std::cout << ']';
        mStates.pop_back();
    }
};