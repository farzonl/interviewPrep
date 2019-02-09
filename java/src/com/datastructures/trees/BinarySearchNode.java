package com.datastructures.trees;

public class BinarySearchNode<T extends Comparable<T>> implements Comparable<BinarySearchNode<T>> {
    private T data;
    private BinarySearchNode<T> left;
    private BinarySearchNode<T> right;

    public BinarySearchNode(T value) {
        this.data = value;
    }

    public BinarySearchNode<T> getLeft() {
        return this.left;
    }

    public void setLeft(BinarySearchNode<T> newLeft) {
        this.left = newLeft;
    }

    public void setRight(BinarySearchNode<T> newRight) {
        this.right = newRight;
    }

    public BinarySearchNode<T> getRight() {
        return this.right;
    }

    public T getData() {
        return this.data;
    }

    public int compareTo(BinarySearchNode<T> o) {
        return getData().compareTo(o.getData());
    }
}