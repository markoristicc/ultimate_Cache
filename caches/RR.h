#ifndef ULTIMATE_CACHE_RR_H
#define ULTIMATE_CACHE_RR_H

#include "cache.h"

#include <set>
#include <random>

class RR : public Cache {
private:
    int m_capacity;

    std::set<int> m_entries;

    std::default_random_engine* m_generator;

public:
    explicit RR(int capacity);

    bool request(int element) override;
};


#endif //ULTIMATE_CACHE_RR_H
