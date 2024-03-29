#ifndef __CH__16_HPP__
#define __CH__16_HPP__

#include <map>
#include <vector>

class wordFreq {
    public:
        wordFreq(std::string book);
        int getFreq(std::string word);
    private:
        std::map<std::string, int> freq;
};

class Vec2 {
    public:
        Vec2() : x(0),y(0) {}
        Vec2(double x1, double y1);
        float cross(const Vec2 &b);
        static float cross(const Vec2 &a, const Vec2 &b);
        double x,y;
};

enum class TTPIECE { EMPTY, X , O };

class TicTacToeBoard {
    public:
        int board[3][3];
        TicTacToeBoard();
        void place(int i, int j, TTPIECE p);
        TTPIECE get(int i , int j);
        
};

class Line {
    public:
        Line(const Vec2 &p1, const Vec2 &p2);
        bool isIntersected(Line &l, Vec2& out);
        double slope, yIntercept;
        Vec2 a;
        Vec2 b;
        int A,B,C;
};

class Operations {
    public:
        static int multiply(int a, int b);
        static int divide(int a, int b);
        static int subtract(int a, int b);
};

class ch16 {
    public:
        static void swapNoTemp(int &a, int &b);
        static void swapSub(int &a, int &b);
        static int maxNoCompare(int a, int b);
        static std::pair<int,int> smallestDiffBrute(int *a, int aLen, int *b, int bLen);
        static std::pair<int,int> smallestDiffSort(int *a, int aLen, int *b, int bLen);
        static bool isWinningBoard(TicTacToeBoard &tb);
        static int contigSeqSum(std::vector<int> &arr);
        static std::pair<int, int> contigSeqIndicies(std::vector<int> &arr);
    private:
        ch16() = delete;
};
#endif // __CH__16_HPP__