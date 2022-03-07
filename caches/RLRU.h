#ifndef ULTIMATE_CACHE_RLRU_H
#define ULTIMATE_CACHE_RLRU_H

#include "cache.h"

#include <set>
#include <unordered_map>
#include <random>

// Random 1-bit LRU
class RLRU : public Cache {
private:
    int m_capacity;

    std::set<int> m_entries;
    std::unordered_map<int, bool> m_marks;

    std::default_random_engine* m_generator;

public:
    explicit RLRU(int capacity);

    bool request(int) override;
};


#endif //ULTIMATE_CACHE_RLRU_H
