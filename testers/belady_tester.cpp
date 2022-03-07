#include "belady_tester.h"

#include <iostream>

BeladyTester::BeladyTester(int capacity)
        : m_capacity(capacity),
          m_total(0), m_missed(0) {}

void BeladyTester::test(const std::vector<int> &seq) {
  m_total += seq.size();

  std::set<int> _cur;

  for (int i = 0; i < seq.size(); i++) {
    if (_cur.find(seq[i]) == _cur.end()) { // Page fault
      m_missed += 1;

      if (_cur.size() == m_capacity) { // Eviction?
        int last_index = 0; // yes yes yes
        int last_ele = 0;

        for (auto e: _cur) {
          int cur_index = -1;

          for (int j = i + 1; j < seq.size(); j++) {
            if (seq[j] != e) continue;

            cur_index = j;
            break;
          }

          if (cur_index < 0) { // Good, no request found, immediate eviction
            cur_index = seq.size() - 1;
          }

          if (cur_index > last_index) {
            last_index = cur_index;
            last_ele = e;
          }
        }

        _cur.erase(last_ele); // Remove useless entry
      }

      // Now just add it
      _cur.insert(seq[i]);
    }
  }
}
