#ifndef ULTIMATE_CACHE_CMB_H
#define ULTIMATE_CACHE_CMB_H

#include "cache.h"

#include <unordered_map>
#include <set>

class CMB : public Cache {
private:
    int m_capacity;
    double m_epsilon;

    int m_cur_cycle;

    std::set<int> m_entries;
    std::unordered_map<int, double> m_cycles;

    static double normal_pdf(double x, double m, double s);
    double calc_priority(int element);

public:
    explicit CMB(int capacity, double epsilon);

    bool request(int element) override;
};


#endif //ULTIMATE_CACHE_CMB_H
