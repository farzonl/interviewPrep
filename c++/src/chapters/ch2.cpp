#include "ch2.hpp"
#include <math.h>  // pow
#include <iostream>

int ch2::sumLists(List<int>* l1, List<int>* l2) {
    Node<int>* curr1 = l1->getHead();
    Node<int>* curr2 = l2->getHead();
    int sumL1 = 0;
    int sumL2 = 0;
    //std::cout << "l1 size: " << l1->Size() << std::endl;
    for(int i = 0; i < l1->Size(); i++) {
        sumL1 += curr1->data*pow(10, i);
        curr1 = curr1->Next;
        //std::cout << "sumL1: " << sumL1 << " after: " << i << std::endl;
    }

    //std::cout << "l2 size: " << l2->Size() << std::endl;
    for(int i = 0; i < l2->Size(); i++) {
        sumL2 += curr2->data*pow(10, i);
        curr2 = curr2->Next;
        //std::cout << "sumL2: " << sumL2 << " after: " << i << std::endl;
    }

    return sumL1 + sumL2;
}

int ch2::sumListsReverse(List<int>* l1, List<int>* l2) {
    Node<int>* curr1 = l1->getHead();
    Node<int>* curr2 = l2->getHead();
    int sumL1 = 0;
    int sumL2 = 0;
    //std::cout << "l1 size: " << l1->Size() << std::endl;
    for(int i = l1->Size()-1; i >= 0 ; i--) {
        sumL1 += curr1->data*pow(10, i);
        curr1 = curr1->Next;
        //std::cout << "sumL1: " << sumL1 << " after: " << i << std::endl;
    }

    //std::cout << "l2 size: " << l2->Size() << std::endl;
    for(int i = l2->Size()-1; i >= 0 ; i--) {
        sumL2 += curr2->data*pow(10, i);
        curr2 = curr2->Next;
        //std::cout << "sumL2: " << sumL2 << " after: " << i << std::endl;
    }

    return sumL1 + sumL2;
}

Queue<int>* ch2::sumListsQueue(List<int>* l1, List<int>* l2) {
    int sum = ch2::sumLists(l1, l2);
    int curr = sum;
    Queue<int>* sumQ = new Queue<int>();
    int i = 1;
    while(curr > 0) {
        sumQ->push(curr % 10);
        curr = sum / pow(10, i);
        //std::cout << "sum: " << curr << " after: " << i << std::endl;
        i++;
    }
    return sumQ;
}

Stack<int>* ch2::sumListsReverseStack(List<int>* l1, List<int>* l2) {
    int sum = ch2::sumListsReverse(l1, l2);
    int curr = sum;
    Stack<int>* sumS = new Stack<int>();
    int i = 1;
    while(curr > 0) {
        sumS->push(curr % 10);
        curr = sum / pow(10, i);
        i++;
    }
    return sumS;
}