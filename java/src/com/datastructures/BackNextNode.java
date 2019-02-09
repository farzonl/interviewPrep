package com.datastructures;

public class BackNextNode<T> {
    private BackNextNode<T> back;
    private BackNextNode<T> next;
    private T data;

    public BackNextNode(T value) {
        this.setData(value);
    }

    public BackNextNode<T> getBack() {
        return this.back;
    }

    public void setBack(BackNextNode<T> newBack) {
        this.back = newBack;
    }

    public T getData() {
        return this.data;
    }

    public void setData(T newData) {
        this.data = newData;
    }

    public BackNextNode<T> getNext() {
        return this.next;
    }

    public void setNext(BackNextNode<T> newNext) {
        this.next = newNext;
    }

    @Override
    public String toString() {
        String back = this.back != null ? ""+this.back.data : "null";
        String next = this.next != null ? ""+this.next.data : "null";
        return back + "<-" + this.data + "->" + next;
    }
}