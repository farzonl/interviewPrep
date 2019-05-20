#include "ch16.hpp"
#include <iostream>
#include <sstream> 
#include <vector>
#include <algorithm>
#include <iterator>
#include <locale>
#include <stdio.h>

TicTacToeBoard::TicTacToeBoard() {
    memset(this->board, 0, sizeof(this->board[0][0]) * 9); // 3 * 3
}

void TicTacToeBoard::place(int i, int j, TTPIECE p) {
    this->board[i][j] = (int) p;
}

TTPIECE TicTacToeBoard::get(int i , int j) {
    if(i < 0 || j < 0 || i >= 3 || j >= 3) {
        return TTPIECE::EMPTY;
    }
    return (TTPIECE) this->board[i][j];
}

Vec2::Vec2(double x1, double y1) : x(x1), y(y1) {
}

float Vec2::cross(const Vec2 &b){ // det product
    return this->x * b.y - this->y * b.x;
}

float Vec2::cross(const Vec2 &a, const Vec2 &b){ // det product
    return a.x * b.y - a.y * b.x;
}

Line::Line(const Vec2 &a, const Vec2 &b): a(a), b(b) { 
    // y-y1 = m(x-x1) -> y = mx + mx1+y1
    // a1x + b1y = c1 (eqn1) y = (-a1x + c1) / b1 -> y = -a1/b1(x) + c1/b1 (slope = -a1/b1) (y-intercept = c1/b1)
    // a2x + b2y = c2 (eqn2)
    // a1b2x + b1b2y = c1b2 (multiply eqn1 by b2)
    // a2b1x + b2b1y = c2b1 (multiply eqn2 by b1)
    // (a1b2 – a2b1) x = c1b2 – c2b1 (subtract eqn1 - eqn2)
    this->A = b.y - a.y; 
    this->B = a.x - b.x; 
    this->C = A*(a.x) + B*(a.y);
}


bool Line::isIntersected(Line &l, Vec2& out) {    
    Vec2 a(this->A,l.A);
    Vec2 b(this->B,l.B);
    double determinant = a.cross(b);

    if (determinant == 0) {
        return false;
    }
    out.x = (l.B*C - B*l.C)/determinant; 
    out.y = (A*l.C - l.A*C)/determinant;
    //std::cout << "(x: " << out.x << ", y: " << out.y << " )" << std::endl;
    return true;
}

std::string toLowerCase(std::string &word) {
    std::locale loc;
    std::stringstream str_stream;
    for(int i = 0; i < word.length();i++) {
        str_stream << std::tolower(word[i], loc);
    }
    return str_stream.str();
}

wordFreq::wordFreq(std::string book) {
    auto split = [](std::string str) {
        std::vector<std::string> words;
        char * pch = strtok (const_cast<char*>(str.c_str())," ,.");
        while (pch != nullptr) {
            words.push_back(std::string(pch));
            pch = strtok (NULL, " ,.");
        }
        return words;
    };
     std::vector<std::string> words = split(book);
     std::map<std::string,int>::iterator it;
     
     for(int i = 0; i < words.size(); i++) {
         std::string currWord = toLowerCase(words[i]);
          it = freq.find(currWord);
          if (it != freq.end()) {
              freq[currWord]++;
          } else {
               freq[currWord] = 1;
          }
     }
}

int wordFreq::getFreq(std::string word) {
    std::map<std::string,int>::iterator it = freq.find(word);
    if (it == freq.end()) {
        return 0;
    }
    return it->second;
}

void print(std::vector<int> const &input)
{
	std::copy(input.begin(),
			input.end(),
			std::ostream_iterator<int>(std::cout, " "));
}



void ch16::swapNoTemp(int &a, int &b) {
    if(a == b) {
        return;
    }
    a ^= b;
    b ^= a;
    a ^= b;
}

void ch16::swapSub(int &a, int &b) {
    // 3 - 6   : -3
    // -3 + 6   : 3
    // 3 - (-3) : 6
    a -= b;
    b += a;
    a = b - a;
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

bool ch16::isWinningBoard(TicTacToeBoard &tb) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int curr = (int) tb.get(i,j);
            if ( ( curr & (int) tb.get(i-1,j-1) ) & ( curr & (int) tb.get(i+1,j+1) ) ) {
                return true;
            }
            if ( ( curr & (int) tb.get(i+1,j+1) ) & ( curr & (int) tb.get(i+1,j+1) ) ) {
                return true;
            }
            if( ( curr & (int) tb.get(i-1,j) ) & ( curr & (int) tb.get(i+1,j) ) ) {
                return true;
            }
            if( ( curr & (int) tb.get(i,j-1) ) & ( curr & (int) tb.get(i,j+1) ) ) {
                return true;
            }
        }
    }
    return false;
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