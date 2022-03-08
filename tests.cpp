#include "caches/LRU.h"
#include "caches/RR.h"
#include "caches/RLRU.h"
#include "caches/MRU.h"

#include "testers/impl_tester.h"
#include "testers/belady_tester.h"

#include "util.h"

#include <iostream>

<<<<<<< HEAD
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

void test_MRU(int capacity) {
  auto _seq = gen_request_seq(2000, 10000);

  MRU _mru{capacity};
  ImplTester _mru_tester{&_mru};
  _mru_tester.test(_seq);
  std::cout << "MRU: " << _mru_tester.miss_ratio() << std::endl;

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
=======
>>>>>>> 1b493cec12eec269c57a2cdc86f76dbf3356f60b

void test_all(int capacity, int k, int m) {
  auto _seq = gen_request_seq(k, m);

  LRU _lru{capacity};
  ImplTester _lru_tester{&_lru};
  _lru_tester.test(_seq);
  std::cout << "LRU: " << _lru_tester.miss_ratio() << std::endl;

  MRU _mru{capacity};
  ImplTester _mru_tester{&_mru};
  _mru_tester.test(_seq);
  std::cout << "MRU: " << _mru_tester.miss_ratio() << std::endl;

  RLRU _rlru{capacity};
  ImplTester _rlru_tester{&_rlru};
  _rlru_tester.test(_seq);
  std::cout << "RLRU: " << _rlru_tester.miss_ratio() << std::endl;

  RR _rr{capacity};
  ImplTester _rr_tester{&_rr};
  _rr_tester.test(_seq);
  std::cout << "RR: " << _rr_tester.miss_ratio() << std::endl;

  RR _mru{capacity};
  ImplTester _mru_tester{&_mru};
  _mru_tester.test(_seq);
  std::cout << "MRU: " << _mru_tester.miss_ratio() << std::endl;

  BeladyTester _belady{capacity};
  _belady.test(_seq);
  std::cout << "opt: " << _belady.miss_ratio() << std::endl;
}

int main() {
  // Mirrors i7-6700HQ CPU with 128KiB L1D and 1MiB L2
  test_all(128, 1024, 100000);

  return 0;
}