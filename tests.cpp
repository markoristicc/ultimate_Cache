#include "caches/LRU.h"
#include "caches/RR.h"
#include "caches/RLRU.h"

#include "testers/impl_tester.h"
#include "testers/belady_tester.h"

#include "util.h"

#include <iostream>

void test_LRU(int capacity) {
  auto _seq = gen_request_seq(2000, 10000);

  ImplTester<LRU> _lru{LRU{capacity}};
  _lru.test(_seq);
  std::cout << "LRU: " << _lru.miss_ratio() << std::endl;

  BeladyTester _belady{capacity};
  _belady.test(_seq);
  std::cout << "opt: " << _belady.miss_ratio() << std::endl;
}

void test_RR(int capacity) {
  auto _seq = gen_request_seq(2000, 10000);

  ImplTester<RR> _rr{RR{capacity}};
  _rr.test(_seq);
  std::cout << "RR: " << _rr.miss_ratio() << std::endl;

  BeladyTester _belady{capacity};
  _belady.test(_seq);
  std::cout << "opt: " << _belady.miss_ratio() << std::endl;
}

void test_RLRU(int capacity) {
  auto _seq = gen_request_seq(2000, 10000);

  ImplTester<RLRU> _rlru{RLRU{capacity}};
  _rlru.test(_seq);
  std::cout << "RLRU: " << _rlru.miss_ratio() << std::endl;

  BeladyTester _belady{capacity};
  _belady.test(_seq);
  std::cout << "opt: " << _belady.miss_ratio() << std::endl;
}

void test_all(int capacity, int k, int m) {
  auto _seq = gen_request_seq(k, m);

  ImplTester<LRU> _lru{LRU{capacity}};
  _lru.test(_seq);
  std::cout << "LRU: " << _lru.miss_ratio() << std::endl;

  ImplTester<RLRU> _rlru{RLRU{capacity}};
  _rlru.test(_seq);
  std::cout << "RLRU: " << _rlru.miss_ratio() << std::endl;

  ImplTester<RR> _rr{RR{capacity}};
  _rr.test(_seq);
  std::cout << "RR: " << _rr.miss_ratio() << std::endl;

  BeladyTester _belady{capacity};
  _belady.test(_seq);
  std::cout << "opt: " << _belady.miss_ratio() << std::endl;
}

int main() {
  test_all(512, 2000, 10000);

  return 0;
}