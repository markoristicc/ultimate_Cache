#include "caches/LRU.h"
#include "caches/RR.h"
#include "caches/RLRU.h"
#include "caches/MRU.h"

#include "testers/impl_tester.h"
#include "testers/belady_tester.h"

#include "util.h"

#include <iostream>

void test_with_seq(int capacity, const std::vector<int>& seq) {
  LRU _lru{capacity};
  ImplTester _lru_tester{&_lru};
  _lru_tester.test(seq);
  std::cout << "LRU: " << _lru_tester.miss_ratio() << std::endl;

  MRU _mru{capacity};
  ImplTester _mru_tester{&_mru};
  _mru_tester.test(seq);
  std::cout << "MRU: " << _mru_tester.miss_ratio() << std::endl;

  RLRU _rlru{capacity};
  ImplTester _rlru_tester{&_rlru};
  _rlru_tester.test(seq);
  std::cout << "RLRU: " << _rlru_tester.miss_ratio() << std::endl;

  RR _rr{capacity};
  ImplTester _rr_tester{&_rr};
  _rr_tester.test(seq);
  std::cout << "RR: " << _rr_tester.miss_ratio() << std::endl;

  BeladyTester _belady{capacity};
  _belady.test(seq);
  std::cout << "opt: " << _belady.miss_ratio() << std::endl;
}

void test_loop(int capacity, int k, int n, int m) {
  auto _seq = gen_loop_request_seq(k, n, m);

  std::cout << "testing loops, c=" << capacity << ", k=" << k << ", n=" << n << ", m=" << m << std::endl;

  test_with_seq(capacity, _seq);
}

int main() {
  // Mirrors i7-6700HQ CPU with 128KiB L1D and 1MiB L2
  test_loop(128, 32, 32, 1500);
  test_loop(128, 64, 32, 3200);
  test_loop(128, 128, 32, 6000);
  test_loop(128, 256, 32, 10000);
  test_loop(128, 512, 16, 10000);
  test_loop(128, 1024, 8, 10000);

  return 0;
}