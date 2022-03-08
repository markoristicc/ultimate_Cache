#include "ULT.h"

#include <iostream>

// Declare the size
ULT::ULT(int n) : csize(n) {}

// requests page x with in the ULT cache
bool ULT::request(int x) {
  bool missed = false;

  // not present in cache
  if (ma.find(x) == ma.end()) {
    freq[x] = 0; //starting freq
    missed = true;
    int f = 0; //used to update freq

    // cache is full
    if (dq.size() == csize) {
      // delete least recently used element
      int last = dq.back(); //least recently used
      int front = dq.front(); //most recently used
      int lf = leastFreq();
      if(freq[last] > avfq){
          if(freq[front] > avfq){
              f = freq[lf];
              dq.erase(ma[lf]);
              ma.erase(lf);
              freq.erase(lf);
              avfq -= (f - avfq)/(csize-1);
          } else{
              f = freq[front];
              dq.pop_front();
              ma.erase(front);
              freq.erase(front);
              avfq -= (f - avfq)/(csize-1);
          }
      } else{
          f = freq[last];
          dq.pop_back();
          ma.erase(last);
          freq.erase(last);
          avfq -= (f - avfq)/(csize-1);
      }
    }
  } else { // present in cache
    dq.erase(ma[x]);
  }

  // update requests
  dq.push_front(x);
  ma[x] = dq.begin();
  freq[x] = freq[x]++;
  avfq += (freq[x] - avfq)/dq.size();
  return missed;
}

// Function to display contents of cache
void ULT::print_entries() {
  // Iterate in the deque and print
  // all the elements in it
  for (const auto &it: dq)
    std::cout << it << " ";

  std::cout << std::endl;
}

int ULT::leastFreq() {
    int min = 0; //arbitrarily large value
    for(int i = 0; i < dq.size(); i++){
        if(freq[dq[min]] > freq[dq[i]])
            min = i;
    }
    return min;
}
