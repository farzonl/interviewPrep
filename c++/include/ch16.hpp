#ifndef __CH__16_HPP__
#define __CH__16_HPP__

#include <map>

class ch16 {
    public:
        static int maxNoCompare(int a, int b);
        static std::pair<int,int> smallestDiffBrute(int *a, int aLen, int *b, int bLen);
        static std::pair<int,int> smallestDiffSort(int *a, int aLen, int *b, int bLen);
    private:
        ch16() = delete;
};
#endif // __CH__16_HPP__