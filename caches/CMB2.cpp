#include "CMB2.h"

#include <cmath>

CMB2::CMB2(int capacity)
        : m_capacity(capacity),
          m_initial_epsilon(0.5),
          m_epsilon(m_initial_epsilon),
          m_cur_cycle(0),
          m_hits_cur_cycle(0),
          m_generator(new std::default_random_engine{std::random_device{}()}) {}

bool CMB2::request(int element) {
  if (m_cur_cycle % m_capacity == 0) {
    clock_event();
  }

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
    m_hits_cur_cycle += 1;
  }

  m_cycles[element] = m_cur_cycle;

  m_cur_cycle += 1;

  return hit;
}

void CMB2::clock_event() {
  std::uniform_int_distribution<int> switch_dist(0, 1 + 100 * m_hits_cur_cycle / m_capacity);
  bool _switch = (switch_dist(*m_generator) == 0);
  std::uniform_int_distribution<int> reset_dist(0, 100 * m_initial_epsilon / m_epsilon);
  bool _reset = (reset_dist(*m_generator) == 0);

  m_hits_cur_cycle = 0;

  if (_switch) {
    if (_reset) {
      m_epsilon = m_initial_epsilon;
    } else {
      m_epsilon *= 1.5;
    }
  }
}

double CMB2::normal_pdf(double x, double m, double s) {
  static const float inv_sqrt_2pi = 0.3989422804014327;
  float a = (x - m) / s;

  return inv_sqrt_2pi / s * std::exp(-0.5f * a * a);
}

double CMB2::calc_priority(int element) {
  auto ele_cycles = m_cur_cycle - m_cycles[element];

  return normal_pdf(ele_cycles, m_capacity * m_epsilon, m_capacity * m_epsilon / 2);
}
