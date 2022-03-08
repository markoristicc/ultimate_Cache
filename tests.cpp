#include "caches/LRU.h"
#include "caches/RR.h"
#include "caches/MRU.h"
#include "caches/LFU.h"
#include "caches/ULT.h"
#include "caches/CMB.h"
#include "caches/CMB2.h"

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

  MRU _lfu{capacity};
  ImplTester _lfu_tester{&_lfu};
  _lfu_tester.test(seq);
  std::cout << _lfu_tester.miss_ratio();

  std::cout << " ";

  RR _rr{capacity};
  ImplTester _rr_tester{&_rr};
  _rr_tester.test(seq);
  std::cout << _rr_tester.miss_ratio();

  std::cout << " ";

  ULT _ult{capacity};
  ImplTester _ult_tester{&_ult};
  _ult_tester.test(seq);
  std::cout << _ult_tester.miss_ratio();

  std::cout << " ";

  CMB _cmb{capacity, 1};
  ImplTester _cmb_cache{&_cmb};
  _cmb_cache.test(seq);
  std::cout << _cmb_cache.miss_ratio();

  std::cout << " ";

  CMB2 _cmb2{capacity};
  ImplTester _cmb2_cache{&_cmb2};
  _cmb2_cache.test(seq);
  std::cout << _cmb2_cache.miss_ratio();

  std::cout << std::endl;
}

void test_random(int capacity, int k, int m) {
  auto _seq = gen_request_seq(k, m);

//  std::cout << "testing random, c=" << capacity << ", k=" << k << ", m=" << m << std::endl;

  test_with_seq(capacity, _seq);
}

void test_norm(int capacity, int k, int m) {
  auto _seq = gen_norm_seq(k, m);

  test_with_seq(capacity, _seq);
}

void test_loop(int capacity, int k, int n, int m) {
  auto _seq = gen_loop_request_seq(k, n, m);

//  std::cout << "testing loops, c=" << capacity << ", k=" << k << ", n=" << n << ", m=" << m << std::endl;

  test_with_seq(capacity, _seq);
}

void test_loop_cmb(int capacity, int k, int n, int m) {
  auto _seq = gen_norm_seq(k, m);

  BeladyTester _belady{capacity};
  _belady.test(_seq);
  std::cout << _belady.miss_ratio();

  std::cout << " ";

  std::vector<double> epsilons{-0.1, 0.1, 1, 2};

  for (auto epsilon: epsilons) {
    CMB _cmb{capacity, epsilon};
    ImplTester _cmb_cache{&_cmb};
    _cmb_cache.test(_seq);
    std::cout << _cmb_cache.miss_ratio();

    std::cout << " ";
  }

  std::cout << std::endl;
}
