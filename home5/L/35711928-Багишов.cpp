
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
// Для простых примитивных типов (int, bool, char и т. д.) и plain old data
template <typename T>
std::enable_if_t<std::is_trivial<T>::value> SerializeTrivial(T pod, std::ostream& out) {
    out.write(reinterpret_cast<char const*>(&pod), sizeof(T));
}

template <typename T>
std::enable_if_t<std::is_trivial<T>::value> DeserializeTrivial(T& pod, std::istream& in) {
    char buf[sizeof(T)];
    char* pbuf = buf;
    in.read(pbuf, sizeof(T));
    std::memcpy(static_cast<void*>(&pod), pbuf, sizeof(T));
}

template <typename T>
struct SerdeTraits {
    static void Serialize(T const& data, std::ostream& out) {
        SerializeTrivial(data, out);
    }

    static void Deserialize(T& data, std::istream& in) {
        DeserializeTrivial(data, in);
    }
};

template <typename T>
struct SerdeTraits<std::vector<T>> {
    static void Serialize(std::vector<T> const& data, std::ostream& out) {
        SerdeTraits<size_t>::Serialize(data.size(), out);
        for (auto const& x : data) {
            SerdeTraits<T>::Serialize(x, out);
        }
    }

    static void Deserialize(std::vector<T>& data, std::istream& in) {
        size_t len;
        SerdeTraits<size_t>::Deserialize(len, in);
        for (size_t i = 0; i < len; ++i) {
            T item;
            SerdeTraits<T>::Deserialize(item, in);
            data.push_back(item);
        }
    }
};

template <typename K, typename V>
struct SerdeTraits<std::map<K, V>> {
    static void Serialize(std::map<K, V> const& data, std::ostream& out) {
        SerdeTraits<size_t>::Serialize(data.size(), out);
        for (auto const& x : data) {
            SerdeTraits<K>::Serialize(x.first, out);
            SerdeTraits<V>::Serialize(x.second, out);
        }
    }

    static void Deserialize(std::map<K, V>& data, std::istream& in) {
        size_t len;
        SerdeTraits<size_t>::Deserialize(len, in);
        for (size_t i = 0; i < len; ++i) {
            K key;
            V value;
            SerdeTraits<K>::Deserialize(key, in);
            SerdeTraits<V>::Deserialize(value, in);
            data[key] = value;
        }
    }
};

template <>
struct SerdeTraits<std::string> {
    static void Serialize(std::string const& data, std::ostream& out) {
        SerdeTraits<size_t>::Serialize(data.size(), out);
        out.write(data.data(), data.size());
    }

    static void Deserialize(std::string& data, std::istream& in) {
        size_t len;
        SerdeTraits<size_t>::Deserialize(len, in);
        data.resize(len);
        in.read(data.data(), len);
    }
};

template <typename T>
void Serialize(T const& data, std::ostream& out) {
    SerdeTraits<T>::Serialize(data, out);
}

template <typename T>
void Deserialize(std::istream& in, T& data) {
    SerdeTraits<T>::Deserialize(data, in);
}