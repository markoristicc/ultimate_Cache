#ifndef ULTIMATE_CACHE_IMPL_TESTER_H
#define ULTIMATE_CACHE_IMPL_TESTER_H

#include "tester.h"
#include "caches/cache.h"

class ImplTester : public Tester {
private:
    int m_total;
    int m_missed;

    Cache *m_impl;

public:
    explicit ImplTester(Cache *impl);

    void test(const std::vector<int> &seq) override;

    double miss_ratio() override {
      return static_cast<double>(m_missed) / m_total;
    }
};

#endif //ULTIMATE_CACHE_IMPL_TESTER_H
