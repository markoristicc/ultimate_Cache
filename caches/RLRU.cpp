#include "RLRU.h"

RLRU::RLRU(int capacity)
        : m_capacity(capacity),
          m_generator(new std::default_random_engine{std::random_device{}()}) {}

bool RLRU::request(int element) {
  bool missed = false;

  auto idx = m_entries.find(element);
  if (idx == m_entries.end()) { // Page fault
    missed = true;

    if (m_entries.size() == m_capacity) { // Cache full
      int entries_unmarked = 0;
      for (auto e : m_entries) {
        if (!m_marks[e]) {
          entries_unmarked += 1;
        }
      }

      if (entries_unmarked < 1) { // All marked?
        for (auto e : m_entries) {
          m_marks[e] = false;
        }
        entries_unmarked = m_capacity;
      }

      std::uniform_int_distribution<int> distribution(0, entries_unmarked - 1);
      int idx_to_pop = distribution(*m_generator);

      for (auto it = m_entries.begin(); it != m_entries.end(); it++) {
        if (idx_to_pop == 0) {
          m_entries.erase(it);
          m_marks.erase(*it);
          break;
        }
        idx_to_pop -= 1;
      }
    }

    m_entries.insert(element);
    m_marks.emplace(element, true);
  }

  return missed;
}
