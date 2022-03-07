#ifndef ULTIMATE_CACHE_IMPL_TESTER_H
#define ULTIMATE_CACHE_IMPL_TESTER_H

#include "tester.h"

template<typename C>
class ImplTester : public Tester {
private:
    int m_total;
    int m_missed;

    C m_impl;

public:
    explicit ImplTester(C impl)
            : m_impl(impl),
              m_total(0),
              m_missed(0) {}

    void test(const std::vector<int> &seq) override {
      for (auto e: seq) {
        m_total += 1;
        if (m_impl.request(e)) {
          m_missed += 1;
        }
      }
    }

    double miss_ratio() override {
      return static_cast<double>(m_missed) / m_total;
    }
};

#endif //ULTIMATE_CACHE_IMPL_TESTER_H
