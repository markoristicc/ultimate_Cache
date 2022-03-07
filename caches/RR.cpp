#include "RR.h"

#include <iostream>


RR::RR(int capacity)
        : m_capacity(capacity),
          m_generator(new std::default_random_engine{std::random_device{}()}) {}

bool RR::request(int element) {
  bool missed = false;

  auto idx = m_entries.find(element);
  if (idx == m_entries.end()) { // Page fault
    missed = true;

    if (m_entries.size() == m_capacity) { // Cache full
      std::uniform_int_distribution<int> distribution(0, m_capacity - 1);

      int idx_to_pop = distribution(*m_generator);
      auto ele_to_pop = std::next(m_entries.begin(), idx_to_pop);

      m_entries.erase(ele_to_pop); // Inefficient
    }

    m_entries.insert(element);
  }

  return missed;
}
