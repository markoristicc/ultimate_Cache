// stl implementation of LRU alg, modified from: https://www.geeksforgeeks.org/lru-cache-implementation/
#include <list>
#include <unordered_map> 
#include <iostream>
using namespace std;

class LRUCache {
	// store pages of cache
	list<int> dq;
	int requests;
	int misses;

	// store requests of page in cache
	unordered_map<int, list<int>::iterator> ma;
	int csize; // maximum capacity of cache

public:
	LRUCache(int);
	void request(int);
	void display();
	void printMR();
};
