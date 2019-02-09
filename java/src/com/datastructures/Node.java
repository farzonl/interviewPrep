package com.datastructures;

public class Node<T> {
    private Node<T> next;
    private T data;

    public Node(T data) {
        this.data = data;
    }

    public T getData() {
        return this.data;
    }

    public void setData(T newData) {
        this.data = newData;
    }

    public Node<T> getNext() {
        return this.next;
    }

    public void setNext(Node<T> newNext) {
        this.next = newNext;
    }
}