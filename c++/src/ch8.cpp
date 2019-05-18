#include "ch8.hpp"

int recurse(int sum, int a, int b) { 
    if( b == 0) {
         return sum;
    }
    return recurse(sum+a, a, --b);
}

 int ch8::recursiveMultiply(int a, int b) {

    return recurse(0,a, b);
 }

 int ch8::iterativeMultiply(int a, int b) {
     int sum = 0;
     for(int i = 0; i < b; i++) {
         sum += a;
     }
     return sum;
 }


