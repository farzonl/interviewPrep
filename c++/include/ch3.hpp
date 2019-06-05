#ifndef __CH__3_HPP__
#define __CH__3_HPP__
#include "linkedList.hpp"

class minStack : public Stack<int> {
    public:
        virtual void push(int data) override;
        virtual void pop() override;
        int min();
    private:
        Stack<int> minStack;
};

/*class ch3 {
    private:
        ch3() = delete;
};*/

#endif // __CH__3_HPP__