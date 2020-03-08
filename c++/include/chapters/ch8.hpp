#ifndef __CH__8_HPP__
#define __CH__8_HPP__

#include <vector>

class ch8 {
    public:
        static int recursiveMultiply(int a, int b);
        static int iterativeMultiply(int a, int b);
        static int magicNumberBrute(int* arr, int length);
        static int magicNumber(int* arr, int length);
        static std::vector<std::vector<char>> subset(std::vector<char> set);
    private:
        ch8() = delete;
};
#endif // __CH__8_HPP__