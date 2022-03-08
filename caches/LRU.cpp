#include "LRU.h"

#include <iostream>

// Declare the size
LRU::LRU(int n) : csize(n) {}

// requests page x with in the LRU cache
bool LRU::request(int x) {
  bool hit = false;

  // not present in cache
  if (ma.find(x) == ma.end()) {
    // cache is full
    if (dq.size() == csize) {
      // delete least recently used element
      int last = dq.back();

      // Pops the last element
      dq.pop_back();

      // Erase the last
      ma.erase(last);
    }
  } else { // present in cache
    hit = true;
    dq.erase(ma[x]);
  }

  // update requests
  dq.push_front(x);
  ma[x] = dq.begin();

  return hit;
}

// Function to display contents of cache
void LRU::print_entries() {
  // Iterate in the deque and print
  // all the elements in it
  for (const auto &it: dq)
    std::cout << it << " ";

  std::cout << std::endl;
}
