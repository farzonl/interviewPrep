package com.datastructures.linkedlists;

import org.junit.Test;
import static org.junit.Assert.*;

import com.datastructures.linkedlists.DoublyLinkedCircularList;

public class DoublyLinkedCircularListTest {

    @Test
    public void testAddFront() {
        DoublyLinkedCircularList<Integer> list = new DoublyLinkedCircularList<Integer>();
        
        for(int i = 0; i < 10; i++) {
            list.addFront(i);
        }
        Integer[] expectedArr = { new Integer(9), new Integer(8) , 
            new Integer(7), new Integer(6), new Integer(5), 
            new Integer(4), new Integer(3),new Integer(2), new Integer(1), new Integer(0) };
        assertArrayEquals(expectedArr, list.toArray());
        assertEquals(expectedArr.length, list.getCount());
        assertEquals("0<-9->8 9<-8->7 8<-7->6 7<-6->5 6<-5->4 5<-4->3 4<-3->2 3<-2->1 2<-1->0 1<-0->9 ", list.toString());

    }

    @Test
    public void testAddBack() {
        DoublyLinkedCircularList<Integer> list = new DoublyLinkedCircularList<Integer>();
        for(int i = 0; i < 10; i++) {
            list.addBack(i);
        }
        Integer[] expectedArr = { new Integer(0), new Integer(1) , 
            new Integer(2), new Integer(3), new Integer(4), 
            new Integer(5), new Integer(6),new Integer(7), new Integer(8), new Integer(9) };
        assertArrayEquals(expectedArr, list.toArray());
        assertEquals(expectedArr.length, list.getCount());
        assertEquals("9<-0->1 0<-1->2 1<-2->3 2<-3->4 3<-4->5 4<-5->6 5<-6->7 6<-7->8 7<-8->9 8<-9->0 ", list.toString());
    }

    @Test
    public void testAdFrontAnddBack() {
        DoublyLinkedCircularList<Integer> list = new DoublyLinkedCircularList<Integer>(5);
        list.addFront(4);
        list.addBack(6);
        list.addFront(3);
        list.addBack(7);
        Integer[] expectedArr = { new Integer(3), new Integer(4), new Integer(5) , 
            new Integer(6), new Integer(7) };
        assertArrayEquals(expectedArr, list.toArray());
        assertEquals(expectedArr.length, list.getCount());
        assertEquals("7<-3->4 3<-4->5 4<-5->6 5<-6->7 6<-7->3 ", list.toString());

    }
}