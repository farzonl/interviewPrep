#ifndef __CH__16_HPP__
#define __CH__16_HPP__

#include <map>

class wordFreq {
    public:
        wordFreq(std::string book);
        int getFreq(std::string word);
    private:
        std::map<std::string, int> freq;
};

class Vec2 {
    public:
        Vec2(double x1, double y1);
        float cross(const Vec2 &b);
        double x,y;
};

class Line {
    public:
        Line(const Vec2 &a, const Vec2 &b);
        bool isIntersected(Line &l);
        double slope, yIntercept;
        Vec2 a;
        Vec2 b;
};

class ch16 {
    public:
        static void swapNoTemp(int &a, int &b);
        static void swapSub(int &a, int &b);
        static int maxNoCompare(int a, int b);
        static std::pair<int,int> smallestDiffBrute(int *a, int aLen, int *b, int bLen);
        static std::pair<int,int> smallestDiffSort(int *a, int aLen, int *b, int bLen);
    private:
        ch16() = delete;
};
#endif // __CH__16_HPP__