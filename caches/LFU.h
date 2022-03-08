#include "cache.h"

#include <list>
#include <unordered_map>

class LFU : public Cache {
private:
    // store pages of cache
    std::list<int> dq;

    // store requests of page in cache
    std::unordered_map<int, std::list<int>::iterator> ma;
    std::unordered_map<int, int> freq;
    int csize; // maximum capacity of cache

    std::list<int>::iterator leastFreq();

public:
    explicit LFU(int);

    bool request(int) override;

    void print_entries();
};