#ifndef ULTIMATE_CACHE_UTIL_H
#define ULTIMATE_CACHE_UTIL_H

#include <vector>
#include <random>

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

// This function generates cache requests
// based on common sequential access of for-each loops.
// args:
// k: number of requests in each loop
// n: number of loops
// m: total number of requests
std::vector<int> gen_loop_request_seq(int k, int n, int m) {
  std::vector<int> seq;
  seq.reserve(m);

  int req_after_each_loop = (m / n) - k;

  std::random_device r;
  std::default_random_engine generator{r()};
  std::uniform_int_distribution<int> distribution(0, k);
  std::minstd_rand aux_distribution{generator()};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      seq.push_back(i * k + distribution(generator));
    }

    for (int j = 0; j < req_after_each_loop; j++) {
      seq.push_back(aux_distribution());
    }
  }

  return seq;
}


#endif //ULTIMATE_CACHE_UTIL_H
