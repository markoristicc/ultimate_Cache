#include "LFU.h"

#include <iostream>

// Declare the size
LFU::LFU(int n) : csize(n) {}

// requests page x with in the LFU cache
bool LFU::request(int x) {
  bool missed = false;

  // not present in cache
  if (ma.find(x) == ma.end()) {
    freq[x] = 0; //starting freq
    missed = true;
    int f = 0; //used to update freq

    // cache is full
    if (dq.size() == csize) {
      // delete least freq used element
      int lf = leastFreq();
      f = freq[lf];
      dq.erase(ma[lf]);
      ma.erase(lf);
      freq.erase(lf);
    }
  } else { // present in cache
    dq.erase(ma[x]);
  }

  // update frequency
  dq.push_front(x); //oo need but its how we keep track
  ma[x] = dq.begin();
  freq[x] = freq[x]++;
  return missed;
}

// Function to display contents of cache
void LFU::print_entries() {
  // Iterate in the deque and print
  // all the elements in it
  for (const auto &it: dq)
    std::cout << it << " ";

  std::cout << std::endl;
}

int LFU::leastFreq() {
    int min = 0; //arbitrarily large value
    for(int i = 0; i < dq.size(); i++){
        if(freq[dq[min]] > freq[dq[i]])
            min = i;
    }
    return min;
}