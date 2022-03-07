// stl implementation of LRU alg, modified from: https://www.geeksforgeeks.org/lru-cache-implementation/

#include "cache.h"

#include <list>
#include <unordered_map>

class LRU : public Cache {
private:
    // store pages of cache
    std::list<int> dq;

    // store requests of page in cache
    std::unordered_map<int, std::list<int>::iterator> ma;
    int csize; // maximum capacity of cache

public:
    explicit LRU(int);

    bool request(int) override;

    void print_entries();
};
