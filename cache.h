#ifndef ULTIMATE_CACHE_CACHE_H
#define ULTIMATE_CACHE_CACHE_H

class Cache {
public:
    // Returns true if page fault occurs
    virtual bool request(int element) = 0;
};

#endif //ULTIMATE_CACHE_CACHE_H
