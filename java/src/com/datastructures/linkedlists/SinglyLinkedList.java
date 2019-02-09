package com.datastructures.linkedlists;

import com.datastructures.Node;

public class SinglyLinkedList<T> {

    private Node<T> head = null;
    private int count;
    public SinglyLinkedList() {
        this.count = 0;
    }

    public SinglyLinkedList(T value) {
        this.add(value);
    }

    public void add(T value) {
        Node<T> newHead = new Node<T>(value);
        newHead.setNext(head);
        head = newHead;
        this.count++;
    }

    public void add(T value, int index) {
        
        if(index > count) {
            throw new IndexOutOfBoundsException();
        }

        if(index == 0) {
            add(value);
            return;
        }

        Node<T> curr = head;
        Node<T> newNode = new Node<T>(value);
        int currIndex = 0;
        while(curr != null) {
            if(currIndex == index-1) {
                newNode.setNext(curr.getNext());
                curr.setNext(newNode);
                break;
            }
            if(curr.getNext() == null) {
                curr.setNext(newNode);
                break;
            }
            curr = curr.getNext();
        }
        this.count++;
    }

    @Override
    public String toString() {
        Node<T> curr = head;
        String returnString = "";
        while(curr != null) {
            returnString += (curr.getData() + "->");
            curr = curr.getNext();
        }
        returnString +="null";
        return returnString;
    }
}