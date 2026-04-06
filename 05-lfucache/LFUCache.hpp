#pragma once

#include <unordered_map>
#include "DoublyLinkedList.hpp"


template<typename K, typename V>
class LFUCache {
private:
    int capacity;
    int size;
    int minimum;
    std::unordered_map<K, Node<K,V>*> cache; 
    std::unordered_map<int, DoublyLinkedList<K,V>*> mp;

    DoublyLinkedList<K, V>* getOrCreateList(int freq);
    void promote(Node<K, V>* node);

public:
    LFUCache(int cap) : capacity(cap), minimum(0), size(0)  {}
    ~LFUCache();
    void set(const K& key, const V& value); 
    V* get(const K& key);
};

template<typename K, typename V>
DoublyLinkedList<K, V>* LFUCache<K, V>::getOrCreateList(int freq) {
    auto it = mp.find(freq);
    if (it != mp.end()) {
        return it->second;
    }

    DoublyLinkedList<K, V>* dll = new DoublyLinkedList<K, V>();
    mp[freq] = dll;
    return dll;
}

template<typename K, typename V>
void LFUCache<K, V>::promote(Node<K, V>* node) {
    int freq = node->freq;
    DoublyLinkedList<K, V>* from = getOrCreateList(freq);
    from->removeNode(node);

    if (freq == minimum && from->getHead() == nullptr) {
        minimum++;
    }

    node->freq++;
    DoublyLinkedList<K, V>* to = getOrCreateList(node->freq);
    to->addNode(node);
}

template<typename K, typename V>
LFUCache<K, V>::~LFUCache() {
    for (auto& item : cache) {
        delete item.second;
    }

    for (auto& bucket : mp) {
        delete bucket.second;
    }
}


template<typename K, typename V>
void LFUCache<K, V>::set(const K& key, const V& value) {
    if (capacity <= 0) {
        return;
    }

    auto it = cache.find(key);
    if (it != cache.end()) {
        Node<K, V>* node = it->second;
        node->value = value;
        promote(node);
        return;
    }

    if (size == capacity) {
        DoublyLinkedList<K,V>* dll = getOrCreateList(minimum);
        Node<K,V>* node = dll->getHead();
        dll->removeNode(node);
        size--;
        cache.erase(node->key);
        delete(node);
    }

    Node<K,V>* node = new Node<K, V>(key, value);
    DoublyLinkedList<K,V>* dll = getOrCreateList(1);
    dll->addNode(node);
    size++;
    minimum = 1;
    cache[key] = node;
}

template<typename K, typename V>
V* LFUCache<K, V>::get(const K& key) {
    auto it = cache.find(key);
    if (it == cache.end()) {
        return nullptr;
    }

    Node<K,V>* node = it->second;
    promote(node);
    return &(node->value);
}