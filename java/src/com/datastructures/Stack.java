package com.datastructures;

public class Stack<T> {
    
    private Node<T> top = null;
    
    public Stack() {}

    public Stack(T value) {
        this.push(value);
    }

    public T peek() {
        if(top == null) {
            return null;
        }
        return top.getData();
    }
    public void pop() {
        if(top == null) {
            return;
        }
        top = top.getNext();
    }

    public void push(T value) {
        Node<T> newTop = new Node<T>(value);
        newTop.setNext(top);
        top = newTop;
    }
}