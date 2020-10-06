template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::find(const Key& key, Value * const value) const {
    auto it = data.find(key);
    if (!(it != data.end())) {
        return 0;
    }
    if (value != nullptr) {
        *value = (*it).second;
    }
    return 1;
}