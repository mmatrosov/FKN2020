#include <iostream>
#include <vector>

class Model {
public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    auto cnt = data.size();
    out.write(reinterpret_cast<char const*>(&cnt), sizeof(cnt));
    out.write(reinterpret_cast<char const*>(data.data()), data.size() * sizeof(int));
}

void Model::load(std::istream& in) {
    size_t cnt;
    in.read(reinterpret_cast<char*>(&cnt), sizeof(cnt));
    data.resize(cnt);
    in.read(reinterpret_cast<char*>(data.data()), data.size() * sizeof(int));
}