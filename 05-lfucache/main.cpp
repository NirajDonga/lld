#include <iostream>
#include "LFUCache.hpp"

void printValue(const char* keyLabel, int* valuePtr) {
    std::cout << keyLabel << " -> ";
    if (valuePtr == nullptr) {
        std::cout << "MISS";
    } else {
        std::cout << *valuePtr;
    }
    std::cout << '\n';
}

int main() {
    LFUCache<int, int> cache(2);

    cache.set(1, 10);
    cache.set(2, 20);

    printValue("get(1)", cache.get(1));
    cache.set(3, 30);

    printValue("get(1)", cache.get(1)); 
    printValue("get(2)", cache.get(2)); 
    printValue("get(3)", cache.get(3)); 

    cache.set(3, 300);
    printValue("get(3)", cache.get(3)); 

    cache.set(4, 40);

    printValue("get(1)", cache.get(1));
    printValue("get(3)", cache.get(3));
    printValue("get(4)", cache.get(4));

    return 0;
}
