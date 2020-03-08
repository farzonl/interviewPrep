#ifndef __CH__1_HPP__
#define __CH__1_HPP__
#include <string>

class ch1 {
    public:
        static bool isUnique(std::string str);
        static bool isUniqueSort(std::string str);
        static bool isPermTable(std::string str1,std::string str2);
        static bool isPermSearch(std::string str1,std::string str2);
        static bool isPermSort(std::string str1,std::string str2);
        static bool isPalindromePerm(std::string str);
        static bool isOneAway(std::string str1, std::string str2);
        static std::string compressString(std::string str);
    private:
        ch1() = delete;
};

#endif