package com.datastructures.trees;

import org.junit.Test;
import static org.junit.Assert.*;

import com.datastructures.trees.BinarySearchTree;
import java.util.ArrayList;
import java.util.Arrays;

public class BinarySearchTreeTest {

    @Test
    public void testAdd() {
        BinarySearchTree<Integer> tree = new BinarySearchTree<Integer>();
        tree.add(40);//          40
        tree.add(60);//      20      60
        tree.add(20);//   10   30  50  70
        tree.add(50);
        tree.add(70);
        tree.add(30);
        tree.add(10);
        ArrayList<Integer> inorderList = tree.getInorder();
        Integer[] inorder = inorderList.toArray(new Integer[inorderList.size()]);
        //System.out.println(Arrays.toString(inorder));
        Integer[] expectedArr = { new Integer(10), new Integer(20),
            new Integer(30), new Integer(40), new Integer(50), new Integer(60),
            new Integer(70) };
        assertArrayEquals(expectedArr, inorder);
    }

    @Test
    public void testBalanced() {
        BinarySearchTree<Integer> tree = new BinarySearchTree<Integer>();
        tree.add(40);                   //           40
        assertTrue(tree.isBalanced()); //         /      \
        tree.add(60);                  //        20        60
        assertTrue(tree.isBalanced()); //      /   \         \
        tree.add(70);                  //    15     30         70
        assertFalse(tree.isBalanced());//             \
        tree.add(20);                 //               35
        assertTrue(tree.isBalanced());
        tree.add(30);
        assertTrue(tree.isBalanced());
        tree.add(35);
        //m(40) = 1 + m(20), m(60) = min =1+ min(1,1) = 1, max =1+max(3,2) = 3 
        //m(20) = 1 + null, m(30) = min = 1+0 = 1, max = 1+ 2 = 3
        //m(30) = 1+ null, m(35) = min = 1+0  = 1, max = 1+1 = 2
        //m(35) = 1+ null,null = 1 
        //m(60) = 1+ null,m(70) min: 1 max = 2
        //m(70) = 1+,null,null = 1
        assertFalse(tree.isBalanced());
        tree.add(15);
        assertFalse(tree.isBalanced());
        tree.add(50);
        assertTrue(tree.isBalanced());
    }
}