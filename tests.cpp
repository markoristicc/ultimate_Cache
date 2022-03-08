#include "caches/LRU.h"
#include "caches/RR.h"
#include "caches/RLRU.h"
#include "caches/MRU.h"
#include "caches/LFU.h"
#include "caches/ULT.h"

#include "testers/impl_tester.h"
#include "testers/belady_tester.h"

#include "util.h"

#include <iostream>

void test_with_seq(int capacity, const std::vector<int> &seq) {
  BeladyTester _belady{capacity};
  _belady.test(seq);
  std::cout << _belady.miss_ratio();

  std::cout << " ";

  LRU _lru{capacity};
  ImplTester _lru_tester{&_lru};
  _lru_tester.test(seq);
  std::cout << _lru_tester.miss_ratio();

  std::cout << " ";

  MRU _mru{capacity};
  ImplTester _mru_tester{&_mru};
  _mru_tester.test(seq);
  std::cout << _mru_tester.miss_ratio();

  std::cout << " ";

  RLRU _rlru{capacity};
  ImplTester _rlru_tester{&_rlru};
  _rlru_tester.test(seq);
  std::cout << _rlru_tester.miss_ratio();

  std::cout << " ";

  RR _rr{capacity};
  ImplTester _rr_tester{&_rr};
  _rr_tester.test(seq);
  std::cout << _rr_tester.miss_ratio();

  std::cout << " ";

  LFU _lfu{capacity};
  ImplTester _lfu_cache{&_lfu};
  _lfu_cache.test(seq);
  std::cout << _lfu_cache.miss_ratio();

  std::cout << " ";

  ULT _ult{capacity};
  ImplTester _ult_cache{&_lfu};
  _ult_cache.test(seq);
  std::cout << _ult_cache.miss_ratio();

  std::cout << std::endl;
}

void test_random(int capacity, int k, int m) {
  auto _seq = gen_request_seq(k, m);

//  std::cout << "testing random, c=" << capacity << ", k=" << k << ", m=" << m << std::endl;

  test_with_seq(capacity, _seq);
}

void test_loop(int capacity, int k, int n, int m) {
  auto _seq = gen_loop_request_seq(k, n, m);

//  std::cout << "testing loops, c=" << capacity << ", k=" << k << ", n=" << n << ", m=" << m << std::endl;

  test_with_seq(capacity, _seq);
}
