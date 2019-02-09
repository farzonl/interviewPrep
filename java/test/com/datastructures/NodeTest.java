package com.datastructures;

import org.junit.Test;
import static org.junit.Assert.*;

public class NodeTest {

    @Test
    public void testNodeGetters() {
        Node<Integer> n = new Node<Integer>(5);
        assertEquals(n.getData(), new Integer(5));
        assertNull(n.getNext());
    }

    @Test
    public void testNodeSetters() {
        Node<Integer> n = new Node<Integer>(5);
        n.setData(6);
        assertEquals(n.getData(), new Integer(6));
        n.setNext(new Node<Integer>(5));
        assertNotNull(n.getNext());
        assertEquals(n.getNext().getData(), new Integer(5));
    }

    @Test
    public void testBackNextNodeGetters() {
        BackNextNode<Integer> n = new BackNextNode<Integer>(5);
        assertEquals(n.getData(), new Integer(5));
        assertNull(n.getBack());
    }

    @Test
    public void testBackNextNodeSetters() {
        BackNextNode<Integer> n = new BackNextNode<Integer>(5);
        n.setData(6);
        assertEquals(n.getData(), new Integer(6));
        n.setBack(new BackNextNode<Integer>(5));
        assertNotNull(n.getBack());

        assertEquals(n.getBack().getData(), new Integer(5));
    }
    
}