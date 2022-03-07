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


#endif //ULTIMATE_CACHE_UTIL_H
