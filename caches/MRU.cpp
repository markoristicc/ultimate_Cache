#include "MRU.h"

#include <iostream>

// Declare the size
MRU::MRU(int n) : csize(n) {}

// requests page x with in the MRU cache
bool MRU::request(int x) {
  bool missed = false;

  // not present in cache
  if (ma.find(x) == ma.end()) {
    missed = true;

    // cache is full
    if (dq.size() == csize) {
      // delete most recently used element
      int front = dq.front();

      // Pops the first element
      dq.pop_front();

      // Erase the front
      ma.erase(front);
    }
  } else { // present in cache
    dq.erase(ma[x]);
  }

  // update requests
  dq.push_front(x);
  ma[x] = dq.begin();

  return missed;
}

// Function to display contents of cache
void MRU::print_entries() {
  // Iterate in the deque and print
  // all the elements in it
  for (const auto &it: dq)
    std::cout << it << " ";

  std::cout << std::endl;
}
