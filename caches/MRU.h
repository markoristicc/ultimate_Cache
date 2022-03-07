#include "cache.h"

#include <list>
#include <unordered_map> //fix

class MRU : public Cache {
private:
    // store pages of cache
    std::list<int> dq; //stack

    // store requests of page in cache
    std::unordered_map<int, std::list<int>::iterator> ma; 
    int csize; // maximum capacity of cache

public:
    explicit MRU(int);

    bool request(int) override;

    void print_entries();
};