template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::find(const Key& key, Value* value) const {
    auto it = data.find(key);
    if (it == data.end()) {
        return false;
    }
    auto val = (*it).second;
    if (value != nullptr)
        *value = val;
    return true;
}
