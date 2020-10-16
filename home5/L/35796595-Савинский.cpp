#include <iostream>
#include <map>
#include <string>
#include <vector>

// Для простых примитивных типов (int, bool, char и т. д.) и plain old data
template <typename T>
void Serialize(T pod, std::ostream& out) {
    out.write(reinterpret_cast<const char*>(&pod), sizeof(pod));
}

void Serialize(const std::string& str, std::ostream& out) {
    size_t sz = str.size();
    out.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
    out.write(reinterpret_cast<const char*>(str.data()), sizeof(char) * str.size());
}

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out);

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out) {
    size_t sz = data.size();
    out.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
    for (const auto& [key, value] : data) {
        Serialize(key, out);
        Serialize(value, out);
    }
}

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out) {
    size_t sz = data.size();
    out.write(reinterpret_cast<const char*>(&sz), sizeof(sz));
    for (const auto& val : data) {
        Serialize(val, out);
    }
}

template <typename T>
void Deserialize(std::istream& in, T& pod) {
    in.read(reinterpret_cast<char*>(&pod), sizeof(pod));
}

void Deserialize(std::istream& in, std::string& str) {
    size_t sz;
    in.read(reinterpret_cast<char*>(&sz), sizeof(sz));
    str.resize(sz);
    in.read(reinterpret_cast<char*>(str.data()), sizeof(char) * str.size());
}

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data);

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data) {
    size_t sz;
    in.read(reinterpret_cast<char*>(&sz), sizeof(sz));
    for (size_t i = 0; i < sz; ++i) {
        T1 key;
        Deserialize(in, key);

        T2 value;
        Deserialize(in, value);

        data[key] = value;
    }
}

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data) {
    size_t sz;
    in.read(reinterpret_cast<char*>(&sz), sizeof(sz));
    data.resize(sz);
    for (size_t i = 0; i < sz; ++i) {
        Deserialize(in, data[i]);
    }
}
