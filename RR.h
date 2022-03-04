#ifndef ULTIMATE_CACHE_RR_H
#define ULTIMATE_CACHE_RR_H

#include <vector>
#include <unordered_map>
#include <set>

class RR {
private:
    std::set<int> m_cache;
    int m_capacity;

    int m_total_requests;
    int m_faults;

public:
    explicit RR(int capacity);

    void request(int element);
};


#endif //ULTIMATE_CACHE_RR_H
