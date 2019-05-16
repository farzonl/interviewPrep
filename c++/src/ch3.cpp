#include "ch3.hpp"

void minStack::push(int n) {
    if(minStack.Size() == 0 || minStack.peek() > n) {
        minStack.push(n);
    }
    Stack::push(n);
}

void minStack::pop() {
    if( minStack.peek() == this->peek()) {
        minStack.pop();
    }
    Stack::pop();
}

int minStack::min() {
    return minStack.peek();
}