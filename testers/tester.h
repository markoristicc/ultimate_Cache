#ifndef ULTIMATE_CACHE_TESTER_H
#define ULTIMATE_CACHE_TESTER_H

#include <vector>
#include <set>

class Tester {
public:
    virtual void test(const std::vector<int> &seq) = 0;
    virtual double miss_ratio() = 0;
};

#endif //ULTIMATE_CACHE_TESTER_H
