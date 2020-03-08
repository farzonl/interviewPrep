
#ifndef __linked__list_HPP__
#define __linked__list_HPP__

#include <iostream> 
#include <stdexcept>

template< typename T >
struct Node {
    T data;
    Node<T>* Next = nullptr;
    Node(T d) : data(d) {}
};

template< typename T >
class List {
protected:
    Node<T>* head = nullptr;
    int size = 0;
    List();
    List(T data);
    virtual ~List() {};
public:
    Node<T>* getHead() { return head;}
    virtual void push(T data) = 0;
    virtual void pop();
    void deleteNode(Node<T>* node);
    T peek();
    void print(); 
    int Size() { return size;}
    bool empty() { return size == 0; }
};

template< typename T >
class Queue : public List<T> {
private:
    Node<T>* tail = nullptr;
public:
    Queue();
    Queue(T data);
    
    virtual void push(T data) override;

    virtual ~Queue();
};

template< typename T >
class Stack : public List<T> {
public:
    Stack();
    Stack(T data);
    virtual void push(T data) override;
    virtual ~Stack();
};

    template< typename T >
    List<T>::List() {
    }

    template< typename T >
    void List<T>::deleteNode(Node<T>* node) {
        Node<T>* next = node->Next;
        node->data = next->data;
        node->Next = next->Next;
        delete next;
        size--;
    }

    template< typename T >
    List<T>::List(T data) : head(new Node<T>(data)), size(1)
    {}

    template< typename T >
    Queue<T>::~Queue() {
        while(this->size > 0) {
            this->pop();
        }
    }

    template< typename T >
    Stack<T>::~Stack() {
        while(this->size > 0) {
            List<T>::pop();
        }
    }

    template< typename T >
    T List<T>::peek() {
        if (this->head == nullptr) {
            throw std::range_error("Datastructure is empty.");
        }

        return this->head->data;
    }

    template < typename T > 
    void List<T>::print() { 
        Node<T> *curr = this->head;
        for (int i = 0; i < this->size; i++) {
            std::cout<<" "<< curr->data;
            curr = curr->Next;
        }
        std::cout<<std::endl; 
    } 

    template< typename T >
    void List<T>::pop() {
        
        if(this->size == 0) {
            return;
        }
        Node<T> *temp = this->head;
        this->head = this->head->Next;
        delete temp;
        temp = nullptr;
        this->size--;
    }

    template< typename T >
    Queue<T>::Queue() : List<T>() {

    }
    
    template< typename T >
    Queue<T>::Queue(T data) : List<T>(data) {
        this->tail = this->head;
    }
    
    template< typename T >
    void Queue<T>::push(T data) {
        Node<T> *temp = new Node<T>(data);
        if(this->size == 0) {
            // assert head == null and tail == null;
            this->tail = temp;
            this->head = temp;
        } else {
            this->tail->Next = temp;
            this->tail = this->tail->Next;
        }
        this->size++;
    }

    template< typename T >
    Stack<T>::Stack() : List<T>() {
    }

    template< typename T >
    Stack<T>::Stack(T data) : List<T>(data) {

    }
    
    template< typename T >
    void Stack<T>::push(T data) {
        Node<T> *temp = new Node<T>(data);
        temp->Next = this->head;
        this->head = temp;
        this->size++;
    }

#endif // __linked__list_HPP__