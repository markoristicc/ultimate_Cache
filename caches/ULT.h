/* think that this alg should choose between LRU, MRU, and LFU, maybe RR. 
unreasonable to implement 1-bit LRU when constantly changing eviction strategies, might consider RR*/

#include "cache.h"

#include <list>
#include <unordered_map>

class ULT : public Cache {
private:
    // store pages of cache
    std::list<int> dq;

    // store requests of page in cache
    std::unordered_map<int, std::list<int>::iterator> ma;
    std::unordered_map<int, int> freq;
    double avfq = 0; //average frequency
    int csize; // maximum capacity of cache

    std::list<int>::iterator leastFreq();

public:
    explicit ULT(int);

    bool request(int) override;

    void print_entries();
};
