#ifndef ULTIMATE_CACHE_CMBA_H
#define ULTIMATE_CACHE_CMBA_H

#include "cache.h"

#include <unordered_map>
#include <set>
#include <random>

class CMB2 : public Cache {
private:
    int m_capacity;

    double m_initial_epsilon;
    double m_epsilon;

    int m_cur_cycle;
    int m_hits_cur_cycle;

    std::set<int> m_entries;
    std::unordered_map<int, double> m_cycles;

    std::default_random_engine* m_generator;

    void clock_event();
    double calc_priority(int element);
    static double normal_pdf(double x, double m, double s);

public:
    explicit CMB2(int capacity);

    bool request(int element) override;
};


#endif //ULTIMATE_CACHE_CMB2_H
