#pragma once    

#include <iostream>

template<typename K, typename V>
struct Node {
    K key;
    V value;
    int freq;
    Node<K, V>* prev;
    Node<K, V>* next;

    Node(const K& key, const V& value) : key(key), value(value), freq(1), prev(nullptr), next(nullptr) {}
};

template<typename K, typename V>
class DoublyLinkedList {
private:
    Node<K, V>* head;
    Node<K, V>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() = default;

    Node<K, V>* getHead() {
        return head;
    }

    Node<K, V>* addNode(Node<K,V>* node) {
        if (node == nullptr) {
            return nullptr;
        }

        node->prev = nullptr;
        node->next = nullptr;

        if(head == nullptr) {
            head = tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        return node;
    }

    void removeNode(Node<K,V>* node) {
        if (node == nullptr) {
            return;
        }

        Node<K, V>* pre = node->prev;
        Node<K, V>* nex = node->next;

        if(pre == nullptr && nex == nullptr) {
            head = nullptr;
            tail = nullptr;
        }
        else if(pre == nullptr) {
            head = head->next;
            head->prev = nullptr;
        }
        else if(nex == nullptr) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            pre->next = nex;
            nex->prev = pre;
        }
        node->next = nullptr;
        node->prev = nullptr;
    }

    void printLinkedList() const {
        Node<K, V>* curr = head;
        while (curr != nullptr) {
            std::cout << "(" << curr->key << ", " << curr->value << ")";
            if (curr->next != nullptr) {
                std::cout << " <-> ";
            }
            curr = curr->next;
        }
        std::cout << std::endl;
    }



};