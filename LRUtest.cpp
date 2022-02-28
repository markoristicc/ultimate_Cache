#include "LRU.h"
#include <stdlib.h>

int main(){
    int a[2048];
    for(int i = 0; i < 2048; i++)
        a[i] = i;
	LRUCache LRU(512);
    int s;
    for(int i = 0; i < 10000; i++){
        s = (int)(((double)rand() * 2048)/ (double)RAND_MAX);
        LRU.request(s);
    }
    LRU.printMR();
	return 0;
}