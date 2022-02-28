#include "LRU.h"

// Declare the size
LRUCache::LRUCache(int n){
	csize = n;
	requests = 0;
	misses = 0;
}

// requests page x with in the LRU cache
void LRUCache::request(int x){
	requests++;
	// not present in cache
	if (ma.find(x) == ma.end()) {
		misses++;
		// cache is full
		if (dq.size() == csize) {
			// delete least recently used element
			int last = dq.back();

			// Pops the last element
			dq.pop_back();

			// Erase the last
			ma.erase(last);
		}
	}

	// present in cache
	else
		dq.erase(ma[x]);

	// update requests
	dq.push_front(x);
	ma[x] = dq.begin();
}

// Function to display contents of cache
void LRUCache::display(){

	// Iterate in the deque and print
	// all the elements in it
	for (auto it = dq.begin(); it != dq.end();
		it++)
		cout << (*it) << " ";

	cout << endl;
}
void LRUCache::printMR(){
	cout<<((double)misses)/requests<<endl;
}

