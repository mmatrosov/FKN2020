// Почему-то не работает...
//
// template <typename Key, typename Value>
// bool KeyValueStorage<Key, Value>::find(const Key& key, Value * const value) const {
//    auto it = std::find(data.begin(), data.end(), key);
//    auto val = *it;
//    if (value != nullptr)
//        value = &val;
//    return it != data.end();
//}

// Ваша реализация функции KeyValueStorage::find будет вставлена сюда:

#include <algorithm>

template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::find(const Key& key, Value* const value) const {
    auto it = data.find(key);
    if (it == data.end())
        return false;
    if (value != nullptr)
        *value = (*it).second;
    return true;
}
