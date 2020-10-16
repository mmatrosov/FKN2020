#include <map>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void Serialize(T pod, std::ostream& out);

void Serialize(const std::string& str, std::ostream& out);

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out);

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out);



template <typename T>
void Deserialize(std::istream& in, T& pod);

void Deserialize(std::istream& in, std::string& str);

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data);

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data);


template <typename T>
void Serialize(T pod, std::ostream& out) {
    out.write(reinterpret_cast<const char*> (&pod), sizeof(pod));
}

void Serialize(const std::string& str, std::ostream& out) {
    size_t sz = str.size();
    out.write(reinterpret_cast<const char*> (&sz), sizeof(sz));
    for (char c : str) {
        Serialize(c, out);
    }
}

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out) {
    size_t sz = data.size();
    out.write(reinterpret_cast<const char*> (&sz), sizeof(sz));
    for (const T& c : data) {
        Serialize(c, out);
    }
}

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out) {
    size_t sz = data.size();
    out.write(reinterpret_cast<const char*> (&sz), sizeof(sz));
    for (const auto& c : data) {
        Serialize(c.first, out);
        Serialize(c.second, out);
    }
}



template <typename T>
void Deserialize(std::istream& in, T& pod) {
    in.read(reinterpret_cast<char*> (&pod), sizeof(pod));
}

void Deserialize(std::istream& in, std::string& str) {
    size_t sz;
    in.read(reinterpret_cast<char*> (&sz), sizeof(sz));
    str = "";
    for (size_t i = 0; i < sz; ++i) {
        char c;
        Deserialize(in, c);
        str += c;
    }
}

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data) {
    size_t sz;
    in.read(reinterpret_cast<char*> (&sz), sizeof(sz));
    data.resize(0);
    for (size_t i = 0; i < sz; ++i) {
        T elem;
        Deserialize(in, elem);
        data.emplace_back(elem);
    }
}

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data) {
    size_t sz;
    in.read(reinterpret_cast<char*> (&sz), sizeof(sz));
    data.clear();
    for (size_t i = 0; i < sz; ++i) {
        T1 key;
        T2 value;
        Deserialize(in, key);
        Deserialize(in, value);
        data.emplace(key, value);
    }
}