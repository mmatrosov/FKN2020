#include <iostream>
#include <map>
#include <string>
#include <vector>

// Для простых примитивных типов (int, bool, char и т. д.) и plain old data
template <typename T>
void Serialize(T pod, std::ostream& out) {
    out.write(reinterpret_cast<char*>(&pod), sizeof(T));
}

void Serialize(const std::string& str, std::ostream& out) {
    Serialize(str.size(), out);
    for (size_t i = 0; i != str.size(); ++i)
        Serialize(str[i], out);
}

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out);

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out);

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out) {
    Serialize(data.size(), out);
    for (size_t i = 0; i != data.size(); ++i)
        Serialize(data[i], out);
}

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out) {
    Serialize(data.size(), out);
    for (const auto& [key, value] : data) {
        Serialize(key, out);
        Serialize(value, out);
    }
}

template <typename T>
void Deserialize(std::istream& in, T& pod) {
    char* str = new char[sizeof(T)];
    in.read(str, sizeof(T));
    pod = *reinterpret_cast<T*>(str);
    delete[] str;
}

void Deserialize(std::istream& in, std::string& str) {
    size_t sz;
    Deserialize(in, sz);
    str.resize(sz);
    for (size_t i = 0; i != sz; ++i)
        Deserialize(in, str[i]);
}

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data);

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data);

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data) {
    size_t sz;
    Deserialize(in, sz);
    data.resize(sz);
    for (size_t i = 0; i != sz; ++i)
        Deserialize(in, data[i]);
}

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data) {
    size_t sz;
    Deserialize(in, sz);
    for (size_t i = 0; i != sz; ++i) {
        T1 key;
        Deserialize(in, key);
        Deserialize(in, data[key]);
    }
}