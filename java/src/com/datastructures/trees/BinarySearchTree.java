package com.datastructures.trees;

import java.util.ArrayList;

public class BinarySearchTree<T extends Comparable<T>> {
    BinarySearchNode<T> head; //root
    int count;
    public BinarySearchTree() {
        count = 0;
    }
    
    public BinarySearchTree(T value) {
       add(value);
    }
    public void add(T value) {
        BinarySearchNode<T> newNode = new BinarySearchNode<T>(value);
        if(head == null) {
            head = newNode;
            return;
        }
        addHelper(head, newNode);
    }

    private void addHelper(BinarySearchNode<T> curr, 
                           BinarySearchNode<T> newNode) {
        if(newNode.compareTo(curr) > 0) {
            if(curr.getRight() == null) {
                curr.setRight(newNode);
                return;
            } else {
                addHelper(curr.getRight(), newNode);
            }
        } else {
            if(curr.getLeft() == null) {
                curr.setLeft(newNode);
                return;
            } else {
                addHelper(curr.getLeft(), newNode);
            }
        }
    }

    public ArrayList<T> getInorder() {
        ArrayList<T> returnList = new ArrayList<T>();
        getInorder(head, returnList);
        return returnList;

    }

    private void getInorder(BinarySearchNode<T> curr, ArrayList<T> arrList) {
        if(curr == null) {
            return;
        }
        getInorder(curr.getLeft(), arrList);
        arrList.add(curr.getData());
        getInorder(curr.getRight(), arrList);
    }

    private int maxDepth(BinarySearchNode<T> curr) {
        if(curr == null) {
            return 0;
        }
        return 1 + Math.max(maxDepth(curr.getLeft()), maxDepth(curr.getRight()));
    }

    private int minDepth(BinarySearchNode<T> curr) {
        if(curr == null) {
            return 0;
        }
        return 1 + Math.min(minDepth(curr.getLeft()), minDepth(curr.getRight()));
    }

    // 4.1 Cracking the coding interview
    public boolean isBalanced() {
        return maxDepth(this.head) - minDepth(this.head) <= 1;
    }


}