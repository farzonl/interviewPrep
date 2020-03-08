#include "ch5.hpp"

int ch5::insertion(int N, int M, int i , int j) {

    int mask = 0;
    for(int k = i; k < j;k++) {
        mask = mask << 1;
        mask += 0x1;
    }
    mask =  -1 ^ (mask << i);
    N = N & mask;
    N = N | (M << i);
    return N;
}

int ch5::conversion(int a, int b) {
    int result = a ^ b;
    int count = 0;
    while(result != 0) {
        if(result & 1) {
            count++;
        }
        result = result >> 1;
    }
    return count;
}