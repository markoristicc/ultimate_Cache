#ifndef ULTIMATE_CACHE_TESTS_H
#define ULTIMATE_CACHE_TESTS_H

#include <vector>

void test_with_seq(int capacity, const std::vector<int>& seq);

void test_random(int capacity, int k, int m);

void test_loop(int capacity, int k, int n, int m);

#endif //ULTIMATE_CACHE_TESTS_H
