#pragma once    

template<typename K, typename V>
struct Node {
    K key;
    V value;
    Node<K, V>* prev;
    Node<K, V>* next;

    Node(const K& key, const V& value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

template<typename K, typename V>
class DoublyLinkedList {
private:
    Node<K, V>* head;
    Node<K, V>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublyLinkedList() {
        while (head) {
            Node<K, V>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Node<K, V>* addNode(const K& key, const V& value) {
        Node<K, V>* node = new Node<K, V>(key, value);
        if(head == nullptr) {
            head = tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
        size++;
        return node;
    }

    void ShiftNode(Node<K, V>* node) {
        
        if(node == tail || node == nullptr) return;

        if(node == head) {
            head = head->next;
            head->prev = nullptr;
            tail->next = node;
            node->prev = tail;
            node->next = nullptr;
            tail = tail->next;
            return;
        }

        Node<K, V>* pre = node->prev;
        Node<K, V>* nex = node->next;

        pre->next = nex;
        nex->prev = pre;

        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail = tail->next;
    }

    void popNode() {

        if(head == nullptr) return;
        size--;
        if(head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node<K, V>* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete(temp);
    }



};