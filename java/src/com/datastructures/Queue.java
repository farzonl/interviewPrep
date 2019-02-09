package com.datastructures;

public class Queue<T> {
    
    private Node<T> front = null;
    private Node<T> back = null;
    
    public Queue() {}

    public Queue(T value) {
        this.enqueue(value);
    }

    public T peek() {
        if(front == null) {
            return null;
        }
        return front.getData();
    }

    public void enqueue(T value) {
        Node<T> newBack = new Node<T>(value);
        if(front == null) {
            front = newBack;
            back  = newBack;
        } else {
            back.setNext(newBack);
            back = newBack;
        }
    }

    public void dequeue() {
        if(front == null) {
            return;
        } else {
            front = front.getNext();
        }
    }
}