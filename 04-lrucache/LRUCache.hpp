#pragma once

#include <unordered_map>
#include "DoublyLinkedList.hpp"


template<typename K, typename V>
class LRUCache {
private:
    int capacity;
    DoublyLinkedList<K, V> dll;
    std::unordered_map<K, Node<K, V>*> cache;

public:
    LRUCache(int cap) : capacity(cap), dll(), cache() {}

    void set(const K& key, const V& value); 
    V* get(const K& key);
};

template<typename K, typename V>
void LRUCache<K, V>::set(const K& key, const V& value) {
    auto it = cache.find(key);
    if (it != cache.end()) {
        Node<K, V>* node = it->second;
        node->value = value;
        dll.ShiftNode(node);
        return;
    }

    if (dll.getSize() == capacity) {
        Node<K, V>* evicted = dll.popNode();
        if (evicted != nullptr) {
            cache.erase(evicted->key);
            delete evicted;
        }
    }

    Node<K, V>* node = dll.addNode(key, value);
    cache[key] = node;
}

template<typename K, typename V>
V* LRUCache<K, V>::get(const K& key) {
    auto it = cache.find(key);
    if (it == cache.end()) {
        return nullptr;
    }

    dll.ShiftNode(it->second);
    return &(it->second->value);
}