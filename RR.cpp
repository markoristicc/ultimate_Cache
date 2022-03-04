#include "RR.h"

#include <random>

RR::RR(int capacity)
        : m_capacity(capacity),
          m_total_requests(0),
          m_faults(0) {}

void RR::request(int element) {
  m_total_requests += 1;

  if (m_cache.find(element) == m_cache.end()) { // Page fault
    m_faults += 1;
  }
}
