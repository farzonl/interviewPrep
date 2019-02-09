package com.datastructures.linkedlists;

import com.datastructures.BackNextNode;

public class DoublyLinkedCircularList<T> {

    BackNextNode<T> head;
    int count;

    public DoublyLinkedCircularList() {
        this.count = 0;
    }

    public DoublyLinkedCircularList(T value) {
        head = new BackNextNode(value);
        initHead(head);
        this.count = 1;
    }
    
    private void initHead(BackNextNode<T> newHead) {
        head.setNext(head);
        head.setBack(head);
    }

    public void addFront(T value) {
        BackNextNode<T> newFront = new BackNextNode(value);
        if(head == null) {
            head = newFront;
            initHead(head);
        } else {
            newFront.setNext(head);
            newFront.setBack(head.getBack());

            head.getBack().setNext(newFront);
            head.setBack(newFront);
        }
        head = newFront;
        this.count++;
    }

    public void addBack(T value) {
        BackNextNode<T> newBack = new BackNextNode(value);
        if(head == null) {
            head = newBack;
            initHead(head);
        } else {
            BackNextNode<T> oldBack = head.getBack();
            newBack.setNext(head);
            newBack.setBack(oldBack);

            oldBack.setNext(newBack);
            head.setBack(newBack);
            
        }
        this.count++;
    }

    public int getCount() {
        return this.count;
    }

    public T[] toArray() {
        BackNextNode<T> curr = head;
        Object[] returnArr = new Object[this.count];
        int i = 0;
        do {
            //System.out.println(curr.toString());
            returnArr[i] = curr.getData();
            curr = curr.getNext();
            i++;
        }while(curr != head);

        return (T[])returnArr;
    }

    @Override
    public String toString() {
        BackNextNode<T> curr = head;
        String returnString = "";
        do {
            returnString += curr.toString() + " ";
            curr = curr.getNext();
        }while(curr != head);

        return returnString;
    }
}