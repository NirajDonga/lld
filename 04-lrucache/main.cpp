#include <iostream>
#include "LRUCache.hpp"

using namespace std;

int main() {
    LRUCache<int, int> cache(2);

    cache.set(1, 10);
    cache.set(2, 20);

    if (int* value = cache.get(1)) {
        cout << "get(1) = " << *value << endl;
    }

    cache.set(3, 30);

    if (int* value = cache.get(2)) {
        cout << "get(2) = " << *value << endl;
    } 
    else {
        cout << "get(2) = not found" << endl;
    }

    if (int* value = cache.get(1)) {
        cout << "get(1) = " << *value << endl;
    }

    if (int* value = cache.get(3)) {
        cout << "get(3) = " << *value << endl;
    }

    return 0;
}