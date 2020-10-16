#include <iostream>
#include <fstream>
#include <vector>

class Model {
public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    size_t sz = data.size();
    out.write(reinterpret_cast<char*>(&sz), sizeof(sz));
    for (size_t i = 0; i != sz; ++i) {
        int val = data[i];
        out.write(reinterpret_cast<char*>(&val), sizeof(int));
    }
}

void Model::load(std::istream& in) {
    size_t sz;
    in.read(reinterpret_cast<char*>(&sz), sizeof(sz));
    data.resize(sz);
    in.read(reinterpret_cast<char*>(data.data()), sizeof(int) * sz);
}