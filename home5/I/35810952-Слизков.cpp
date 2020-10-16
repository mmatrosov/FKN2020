#include <iostream>
#include <vector>

class Model {
public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    size_t sz = data.size();
    out.write(reinterpret_cast<const char*>(&sz), sizeof(size_t));
    out.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(int));
}

void Model::load(std::istream& in) {
    size_t sz;
    in.read(reinterpret_cast<char*>(&sz), sizeof(size_t));
    data.resize(sz);
    in.read(reinterpret_cast<char*>(data.data()), sz * sizeof(int));
}
