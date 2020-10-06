template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::find(const Key& key, Value * const value) const {
    auto it = data.find(key);
    if (it == data.end())
        return false;
    auto val = *it;
    if (value != nullptr)
        *value = val.second;
    return true;
}