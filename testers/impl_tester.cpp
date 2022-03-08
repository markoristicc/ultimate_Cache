#include "impl_tester.h"

ImplTester::ImplTester(Cache *impl)
        : m_impl(impl),
          m_total(0),
          m_missed(0) {}

void ImplTester::test(const std::vector<int> &seq) {
  for (auto e: seq) {
    m_total += 1;
    if (!m_impl->request(e)) {
      m_missed += 1;
    }
  }
}
