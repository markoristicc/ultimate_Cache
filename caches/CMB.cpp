#include "CMB.h"

#include <cmath>

CMB::CMB(int capacity, double epsilon)
        : m_capacity(capacity),
          m_epsilon(epsilon),
          m_cur_cycle(0) {}

bool CMB::request(int element) {
  bool hit = false;

  auto idx = m_entries.find(element);
  if (idx == m_entries.end()) { // Page fault
    if (m_entries.size() == m_capacity) { // Cache full
      int ele_to_pop = *(m_entries.begin());

      for (auto ele: m_entries) {
        if (calc_priority(ele) < calc_priority(ele_to_pop)) {
          ele_to_pop = ele;
        }
      }

      m_entries.erase(ele_to_pop); // Inefficient
      m_cycles.erase(ele_to_pop);
    }

    m_entries.insert(element);
    m_cycles.emplace(element, m_cur_cycle); // Default priority
  } else {
    hit = true;
  }

  m_cycles[element] = m_cur_cycle;

  m_cur_cycle += 1;

  return hit;
}

double CMB::normal_pdf(double x, double m, double s) {
  static const float inv_sqrt_2pi = 0.3989422804014327;
  float a = (x - m) / s;

  return inv_sqrt_2pi / s * std::exp(-0.5f * a * a);
}

double CMB::calc_priority(int element) {
  auto ele_cycles = m_cur_cycle - m_cycles[element];

  return normal_pdf(ele_cycles, m_capacity * m_epsilon, m_capacity * m_epsilon / 2);
}
