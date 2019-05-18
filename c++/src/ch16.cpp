#include "ch16.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void print(std::vector<int> const &input)
{
	std::copy(input.begin(),
			input.end(),
			std::ostream_iterator<int>(std::cout, " "));
}

int ch16::maxNoCompare(int a, int b) { //TODO how to solve overflow?
    auto flip = [](int a) {
        return a^1;
    };
    auto sign = [](int a) {
        return ((a) >> 31) &1; // right shift all positive bits to 0
    };

    int s = sign(a-b); // get the sign after subtraction
    int f = flip(s);
    return s * b + f * a;
}

std::pair<int,int> ch16::smallestDiffBrute(int *a, int aLen, int *b, int bLen) {
    
    int min = std::numeric_limits<int>::max();
    int aVal = a[0];
    int bVal = b[0];

    for(int i = 0; i < aLen; i++) {
        for(int j = 0; j < bLen; j++) {
            int diff = std::abs( a[i] - b[j]);
            if(diff < min) {
                min = diff;
                aVal = a[i];
                bVal = b[j];
            }
        }
    }
    return std::make_pair(aVal,bVal);
}

std::pair<int, int> ch16::smallestDiffSort(int *a, int aLen, int *b, int bLen) {
    std::vector<int> aVec(a,a+aLen);
    std::vector<int> bVec(b,b+bLen);
    std::sort(aVec.begin(), aVec.end());
    std::sort(bVec.begin(), bVec.end());
    
    //print(aVec);
    //std::cout << "" << std::endl;
    //print(bVec);

    int i = 0, j = 0;
    int aVal = aVec[0];
    int bVal = bVec[0];
    int min = std::numeric_limits<int>::max();
    while (i < aVec.size() && j < bVec.size()) {
        int diff = std::abs( aVec[i] - bVec[j]);
        if(diff < min) {
            min = diff;
            aVal = aVec[i];
            bVal = bVec[j];
        }
        if( aVec[i] < bVec[j]) {
           i++;
        } else {
           j++;
        }
    }
    return std::make_pair(aVal,bVal);
}