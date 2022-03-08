#include "ULT.h"

#include <iostream>

// Declare the size
ULT::ULT(int n) : csize(n) {}

// requests page x with in the ULT cache
bool ULT::request(int x) {
  bool hit = false;

  // not present in cache
  if (ma.find(x) == ma.end()) {
    // cache is full
    if (dq.size() == csize) {
      // delete least recently used element
      int last = dq.back(); //least recently used
      int front = dq.front(); //most recently used
      auto lf = leastFreq();
      if (freq[last] > avfq) {
        if (freq[front] > avfq) {
          int f = freq[*lf];
          ma.erase(*lf);
          freq.erase(*lf);
          dq.erase(lf);
          avfq -= (f - avfq) / (csize - 1);
        } else {
          int f = freq[front];
          ma.erase(front);
          freq.erase(front);
          dq.pop_front();
          avfq -= (f - avfq) / (csize - 1);
        }
      } else {
        int f = freq[last];
        dq.pop_back();
        ma.erase(last);
        freq.erase(last);
        avfq -= (f - avfq) / (csize - 1);
      }
    }

    freq[x] = 0; //starting freq
  } else { // present in cache
    hit = true;
    dq.erase(ma[x]);
  }

  // update requests
  dq.push_front(x);
  ma[x] = dq.begin();
  freq[x] += 1;
  avfq += (freq[x] - avfq) / dq.size();
  return hit;
}

// Function to display contents of cache
void ULT::print_entries() {
  // Iterate in the deque and print
  // all the elements in it
  for (const auto &it: dq)
    std::cout << it << " ";

  std::cout << std::endl;
}

std::list<int>::iterator ULT::leastFreq() {
  auto min_it = dq.begin();

  for (auto it = dq.begin(); it != dq.end(); it++) {
    if (freq[*it] < freq[*min_it]) {
      min_it = it;
    }
  }

  return min_it;
}
