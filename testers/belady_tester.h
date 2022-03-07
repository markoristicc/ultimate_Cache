#ifndef ULTIMATE_CACHE_BELADY_TESTER_H
#define ULTIMATE_CACHE_BELADY_TESTER_H

#include "tester.h"

class BeladyTester : public Tester {
private:
    int m_capacity;

    int m_total;
    int m_missed;

public:
    explicit BeladyTester(int capacity);

    void test(const std::vector<int> &seq) override;

    double miss_ratio() override {
      return static_cast<double>(m_missed) / m_total;
    }
};


#endif //ULTIMATE_CACHE_BELADY_TESTER_H
