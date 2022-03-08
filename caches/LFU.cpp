#include "LFU.h"

#include <iostream>

// Declare the size
LFU::LFU(int n) : csize(n) {}

// requests page x with in the LFU cache
bool LFU::request(int x) {
  bool hit = false;

  // not present in cache
  if (ma.find(x) == ma.end()) {
    int f = 0; //used to update freq

    // cache is full
    if (dq.size() == csize) {
      // delete least freq used element
      auto lf = leastFreq();
      ma.erase(*lf);
      freq.erase(*lf);
      dq.erase(lf);
    }

    freq[x] = 0; //starting freq
  } else { // present in cache
    hit = true;
    dq.erase(ma[x]);
  }

  // update frequency
  dq.push_front(x); //oo need but its how we keep track
  ma[x] = dq.begin();
  freq[x] = freq[x]++;

  return hit;
}

// Function to display contents of cache
void LFU::print_entries() {
  // Iterate in the deque and print
  // all the elements in it
  for (const auto &it: dq)
    std::cout << it << " ";

  std::cout << std::endl;
}

std::list<int>::iterator LFU::leastFreq() {
  auto min_it = dq.begin();

  for (auto it = dq.begin(); it != dq.end(); it++) {
    if (freq[*it] < freq[*min_it]) {
      min_it = it;
    }
  }

  return min_it;
}