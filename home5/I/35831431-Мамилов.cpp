#include <iostream>
#include <vector>

class Model {
public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    out << data.size() << ' ' << reinterpret_cast<intptr_t>(&(*data.begin()));
}

void Model::load(std::istream& in) {
    size_t sz;
    in >> sz;
    std::vector<int> tmp(sz);
    intptr_t x;
    in >> x;
    int *it = reinterpret_cast<int*>(x);
    for (size_t i = 0; i < sz; ++i) {
        tmp[i] = *it;
        ++it;
    }
    data = tmp;
}