#ifndef __CH__2_HPP__
#define __CH__2_HPP__
#include "linkedList.hpp"

class ch2 {
    public:
        static int sumLists(List<int>* l1, List<int>* l2);
        static int sumListsReverse(List<int>* l1, List<int>* l2);
        static Queue<int>* sumListsQueue(List<int>* l1, List<int>* l2);
        static Stack<int>* sumListsReverseStack(List<int>* l1, List<int>* l2);
        template< typename T >
        static void deleteMiddleNodeUsingSize(List<T>* l1);
        template< typename T >
        static void deleteMiddleNode(List<T>* l1);
        template< typename T >
        static void isCircular(List<T>* l1);

    private:
        ch2() = delete;
};

template< typename T >
void ch2::deleteMiddleNode(List<T>* l1) {
    Node<T>* curr = l1->getHead();
    int count = 0;
    while(curr != nullptr) {
        curr = curr->Next;
        count++;
    }
    curr = l1->getHead();
    int middle = count /2;
    for(int i = 1; i < middle; i++) {
        curr = curr->Next;
    }
    l1->deleteNode(curr);
}

template< typename T >
void ch2::deleteMiddleNodeUsingSize(List<T>* l1) {
    Node<T>* curr = l1->getHead();
    int middle = l1->Size() / 2;
    for(int i = 1; i < middle; i++) {
        curr = curr->Next;
    }
    l1->deleteNode(curr);
}

#endif // __CH__2_HPP__