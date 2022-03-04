#include "LRU.h"
#include "RR.h"

#include <cstdlib>
#include <vector>
#include <random>
#include <set>

#include <iostream>

// k: number of distinct requests
// m: total number of requests
std::vector<int> gen_request_seq(int k, int m) {
  std::vector<int> seq;
  seq.reserve(m);

  std::random_device r;
  std::default_random_engine generator{r()};
  std::uniform_int_distribution<int> distribution(0, k);

  for (int i = 0; i < m; i++) {
    seq.push_back(distribution(generator));
  }

  return seq;
}

double opt_ratio(std::vector<int> seq, int capacity) {
  int faults = 0;
  {
    std::set<int> _cur;

    for (int i = 0; i < seq.size(); i++) {
      if (_cur.find(seq[i]) == _cur.end()) { // Page fault
        faults += 1;

        if (_cur.size() == capacity) { // Eviction?
          int last_index = 0; // yes yes yes
          int last_ele = 0;

          for (auto e: _cur) {
            int cur_index = -1;

            for (int j = i; j < seq.size(); j++) {
              if (seq[j] != e) continue;

              cur_index = j;
              break;
            }

            if (cur_index < 0) { // Good, no request found, immediate eviction
              cur_index = seq.size() - 1;
            }

            if (cur_index > last_index) {
//              std::cout << "replacing " << last_ele << " with "<< e << std::endl;
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

  return static_cast<double>(faults) / seq.size();
}

void test_LRU() {
  LRUCache LRU(512);
  auto _req = gen_request_seq(2000, 10000);
  for (auto e : _req) {
    LRU.request(e);
  }
  std::cout << "opt: " << opt_ratio(_req, 512) << std::endl;
  LRU.printMR();
}

void test_RR(int capacity) {
  RR rr{capacity};

  auto _req = gen_request_seq(1000, 10000);
//  for (int i = 0; i < 10; i++) {
//    std::cout << _req[i] << std::endl;
//  }
}

int main() {
  test_LRU();
//  test_RR(400);

  return 0;
}