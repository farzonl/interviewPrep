package com.datastructures.linkedlists;

import com.datastructures.BackNextNode;

public class DoublyLinkedList<T> {
    
    BackNextNode<T> head;

    public DoublyLinkedList() {}

    public DoublyLinkedList(T value) {
        head = new BackNextNode(value);
    }

}