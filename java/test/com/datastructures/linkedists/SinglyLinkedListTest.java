package com.datastructures.linkedlists;

import org.junit.Test;
import static org.junit.Assert.*;

import com.datastructures.linkedlists.SinglyLinkedList;

public class SinglyLinkedListTest {

    @Test
    public void testAddFront() {
        SinglyLinkedList<Integer> list = new SinglyLinkedList<Integer>();
        for(int i = 1; i <4; i++) {
            list.add(i);
        }
        assertEquals("3->2->1->null",list.toString());
    }

    @Test
    public void testAddIndex() {
        SinglyLinkedList<Integer> list = new SinglyLinkedList<Integer>();
        list.add(0, 0);
        try {
            list.add(1, 2);
            fail();
        } catch(IndexOutOfBoundsException e) {
            assertTrue(true);
        }
        list.add(2, 1);
        list.add(1, 1);
        list.add(3, 3);
        assertEquals("0->1->2->3->null",list.toString());
    }
}
