#include <iostream>
#include <vector>

const size_t num = sizeof(int);

class Model {
public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    //Нужно вывести точку, потому что иначе кусок строки, отвечающий за size сливается с байтами.
    out << data.size() << ' ' << '.';
    const char* ar = reinterpret_cast<const char*>(data.data());
    out.write(ar, data.size() * num);
}

void Model::load(std::istream& in) {
    size_t sz;
    in >> sz;

    char tmp;
    in >> tmp;

    char* ar = new char[sz * num];
    in.read(ar, sz * num);
    int* ndata = reinterpret_cast<int*>(ar);

    data.resize(sz);
    for (size_t i = 0; i != sz; ++i)
        data[i] = ndata[i];
    delete[] ndata;
}