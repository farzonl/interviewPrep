#ifndef __CH__3_HPP__
#define __CH__3_HPP__
#include "linkedList.hpp"
#include <vector>
#include <stack>
class minStack : public Stack<int> {
    public:
        virtual void push(int data) override;
        virtual void pop() override;
        int min();
    private:
        Stack<int> minStack;
};

template <typename T> 
class SetOfStacks {
    public:
        void push(T data);
        void pop();
        void popAt(int index);
        T peek();
        SetOfStacks(int cap=10) : _cap(cap) {}
    private:
        int _cap;
        int currStack = -1;
        std::vector<std::stack<T>> stacks;
};

template <typename T> 
void SetOfStacks<T>::push(T data) {
    if(stacks.size() == 0 || static_cast<int>(stacks[currStack].size()) == _cap ) {
        std::stack<T> s;
        s.push(data);
        stacks.push_back(s);
        currStack++;
    } else {
        stacks[currStack].push(data);
    }
}

template <typename T> 
void SetOfStacks<T>::popAt(int index) {
    if(stacks.size() == 0 || index >= static_cast<int>(stacks.size()) || 
       index < 0) {
           return;
       }

    if(stacks[index].size() != 0) {
        stacks[index].pop();
    }
    if(stacks[index].size() == 0) {
        // erase the 6th element
        stacks.erase(stacks.begin() + index);
        currStack--;
    }
}

template <typename T> 
void SetOfStacks<T>::pop() {
    if(stacks.size() == 0) {
        return;
    }

    if(stacks[currStack].size() != 0) {
        stacks[currStack].pop();
    }

    if(stacks[currStack].size() == 0) {
        stacks.pop_back();
        currStack--;
    }
}

template <typename T> 
T SetOfStacks<T>::peek() {
    if(stacks.size() == 0 ||
       stacks[currStack].size() == 0) {
        std::cout << "# of stacks: "<< stacks.size()
        << " currStack: "<< currStack << std::endl;
        throw;
    }

    return stacks[currStack].top();
}

/*class ch3 {
    private:
        ch3() = delete;
};*/

#endif // __CH__3_HPP__