#include "ch1.hpp"
#include <climits>
#include <sstream>      // std::stringstream

bool ch1::isUnique(std::string str) {
    bool table[SCHAR_MAX];
    memset(table, 0, sizeof(table));
    for(int i = 0; i < str.size(); i++) {
        int curr = (int)str.at(i);
        if(table[curr] == false) {
            table[curr] = true;
        } else {
            return false;
        }
    }
    return true;
}

// if we can't use aditional data structures then sort the string
bool ch1::isUniqueSort(std::string str) {
    std::sort(str.begin(), str.end());
    for(int i = 1; i < str.size(); i++) {
        if(str.at(i) == str.at(i-1)) {
            return false;
        }
    }
    return true;
}

bool ch1::isPermTable(std::string str1,std::string str2) {
    if(str1.size() != str2.size()) {
        return false;
    }

    int table[SCHAR_MAX];
    memset(table, 0, sizeof(table));
    for(int i = 0; i < str1.size(); i++) {
        int curr = (int)str1.at(i);
        table[curr]++;
    }

    for(int i = 0; i < str2.size(); i++) {
        int curr = (int)str2.at(i);
        table[curr]--;
    }

    for(int i = 0; i < str1.size(); i++) {
        int curr = (int)str1.at(i);
        if(table[curr] != 0) {
            return false;
        }
    }
    return true;
}

bool ch1::isPermSearch(std::string str1,std::string str2) {
    if(str1.size() != str2.size()) {
        return false;
    }
    for(int i = 0; i < str1.size(); i++) {
         for(int j = 0; j < str2.size(); j++) {
             if( str1[i] != 0 && str1[i] == str2[j]) {
                 str1[i] = (char)0;
                 str2[j] = (char)0;
             }
         }
    }
    
    for(int i = 0; i < str1.size(); i++) {
        if(str1[i] != 0) {
            return false;
        }
    }
    return true;
}

bool ch1::isPermSort(std::string str1,std::string str2) {
    if(str1.size() != str2.size()) {
        return false;
    }
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    return str1 == str2;
}

bool ch1::isPalindromePerm(std::string str) {
    int table[SCHAR_MAX];
    memset(table, 0, sizeof(table));
    for(int i = 0; i < str.size(); i++) {
        int curr = (int)str.at(i);
        table[curr]++;
    }
    if(str.size() & 1) { // odd
       int twoCount = 0;
       int oneCount = 0;
       for(int i = 0; i < str.size(); i++) {
           int curr = (int)str.at(i);
           if(table[curr] == 2) {
               twoCount++;
           } else if(table[curr] == 1) {
               oneCount++;
           } else {
               return false;
           }
           if (oneCount > 1) { // optimization
               return false;
           }
           if (twoCount > str.size()-1) { // optimization
               return false;
           }
        }
    } else {
       for(int i = 0; i < str.size(); i++) {
           int curr = (int)str.at(i);
           if(table[curr] != 2) {
               return false;
           }
       }
    }

    return true;
}

bool ch1::isOneAway(std::string str1, std::string str2) {
    if(str1.size() > str2.size() + 1     || 
       str1.size() < str2.size() - 1) {
           return false;
    }
    int errCnt = 0;
    int min =  std::min(str1.size() , str2.size() );
    int max =  std::max(str1.size() , str2.size() );
    for(int i = 0; i < min; i++ ) {
        if(errCnt > 1) {
            return false;
        }
        if(str1[i] != str2[i]) {
            errCnt++;
        }
    }
    if(errCnt == 1 && min != max) {
        return false;
    }
    return true;
}

std::string ch1::compressString(std::string str) {
    int charCount = 1;
    std::stringstream compressedStream;
    for(int i = 1; i < str.size(); i++) {
        if(str[i-1] == str[i]) {
            charCount++;
        }
        else {
            compressedStream <<  str[i-1] << charCount;
            charCount = 1;
        }
    }
    compressedStream <<  str[str.size()-1] << charCount;
    std::string compressedStr = compressedStream.str();

    if(compressedStr.size() > str.size()) {
        return str;
    }

    return compressedStr;
}