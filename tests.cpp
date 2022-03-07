#include "caches/LRU.h"
#include "caches/RR.h"
#include "caches/RLRU.h"

#include "testers/impl_tester.h"
#include "testers/belady_tester.h"

#include "util.h"

#include <iostream>

void test_LRU(int capacity) {
  auto _seq = gen_request_seq(2000, 10000);

  LRU _lru{capacity};
  ImplTester _lru_tester{&_lru};
  _lru_tester.test(_seq);
  std::cout << "LRU: " << _lru_tester.miss_ratio() << std::endl;

  BeladyTester _belady{capacity};
  _belady.test(_seq);
  std::cout << "opt: " << _belady.miss_ratio() << std::endl;
}

void test_RR(int capacity) {
  auto _seq = gen_request_seq(2000, 10000);

  RR _rr{capacity};
  ImplTester _rr_tester{&_rr};
  _rr_tester.test(_seq);
  std::cout << "RR: " << _rr_tester.miss_ratio() << std::endl;

  BeladyTester _belady{capacity};
  _belady.test(_seq);
  std::cout << "opt: " << _belady.miss_ratio() << std::endl;
}

void test_RLRU(int capacity) {
  auto _seq = gen_request_seq(2000, 10000);

  RLRU _rlru{capacity};
  ImplTester _rlru_tester{&_rlru};
  _rlru_tester.test(_seq);
  std::cout << "RLRU: " << _rlru_tester.miss_ratio() << std::endl;

  BeladyTester _belady{capacity};
  _belady.test(_seq);
  std::cout << "opt: " << _belady.miss_ratio() << std::endl;
}

void test_all(int capacity, int k, int m) {
  auto _seq = gen_request_seq(k, m);

  LRU _lru{capacity};
  ImplTester _lru_tester{&_lru};
  _lru_tester.test(_seq);
  std::cout << "LRU: " << _lru_tester.miss_ratio() << std::endl;

  RLRU _rlru{capacity};
  ImplTester _rlru_tester{&_rlru};
  _rlru_tester.test(_seq);
  std::cout << "RLRU: " << _rlru_tester.miss_ratio() << std::endl;

  RR _rr{capacity};
  ImplTester _rr_tester{&_rr};
  _rr_tester.test(_seq);
  std::cout << "RR: " << _rr_tester.miss_ratio() << std::endl;

  BeladyTester _belady{capacity};
  _belady.test(_seq);
  std::cout << "opt: " << _belady.miss_ratio() << std::endl;
}

int main() {
  test_all(512, 2000, 10000);

  return 0;
}