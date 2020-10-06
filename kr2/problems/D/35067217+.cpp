#include <unordered_map>

template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::find(Key const& key, Value* const value) const {
    if (data.count(key) == 0) {  //
        return false;
    }
    if (value != nullptr) {
        *value = data.at(key);
    }
    return true;
}