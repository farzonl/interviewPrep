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

std::vector<std::vector<char>> ch8::subset(std::vector<char> set) {
    std::vector<std::vector<char>> retVec;
    for(int i = 0; i < set.size();i++) {
        std::vector<char> curr;
        for(int j = i; j < set.size();j++) {
            curr.push_back(set[j]);
            std::vector<char> copyVec(curr);
            retVec.push_back(copyVec);
        }
    }
    return retVec;
}

int ch8::magicNumberBrute(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        if(arr[i] == i) {
            return i;
        }
    }
    return -1;
}

int magicNumberBinarySearch(int* arr, int start, int end) {

    if( start > end ) {
        return -1;
    }

    int midpoint = (start + end) / 2;
    if(arr[midpoint] == midpoint) {
        return midpoint;
    }
    else if(arr[midpoint] < midpoint) { // --> go right
        return magicNumberBinarySearch(arr, midpoint + 1, end);
    }
    else { // if(arr[midpoint] > midpoint) { // --> go left
        return magicNumberBinarySearch(arr, start, midpoint - 1);
    }
}

int ch8::magicNumber(int* arr, int length) {
    return magicNumberBinarySearch(arr,0, length - 1);
 }