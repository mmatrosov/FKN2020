#include <iostream>
#include <vector>
#include <sstream>

class Model {
public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    size_t sz = data.size();
    out.write(reinterpret_cast<const char*> (&sz), sizeof(sz));
    out.write(reinterpret_cast<const char*> (data.data()), sizeof(int) * data.size());
}

void Model::load(std::istream& in) {
    size_t sz = data.size();
    in.read(reinterpret_cast<char*> (&sz), sizeof(sz));
    data.resize(sz);
    in.read(reinterpret_cast<char*> (data.data()),
            sizeof(decltype(data.front())) * data.size());
}