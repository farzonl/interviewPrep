package com.datastructures;

import org.junit.Test;
import static org.junit.Assert.*;

public class QueueTest {

    @Test
    public void testPeek() {
        Queue<Integer> q = new Queue<Integer>();
        assertNull(q.peek());
        q.enqueue(5);
        assertEquals(q.peek(), new Integer(5));
        Queue<Integer> q2 = new Queue<Integer>(6);
        assertEquals(q2.peek(), new Integer(6));
    }

    @Test
    public void testAddRemove() {
        Queue<Integer> q = new Queue<Integer>();
        for(int i = 0; i < 10; i++) {
            q.enqueue(i);
        }
        for(int i = 0; i < 10; i++) {
            assertEquals(q.peek(), new Integer(i));
            q.dequeue();
        }
    }

    @Test
    public void testAddRemoveSomeThenAddAndRemove() {
        Queue<Integer> q = new Queue<Integer>();
        for(int i = 0; i < 10; i++) {
            q.enqueue(i);
        }
        for(int i = 0; i < 5; i++) {
            assertEquals(q.peek(), new Integer(i));
            q.dequeue();
        }
        for(int i = 10; i < 15; i++) {
            q.enqueue(i);
        }
        for(int i = 5; i < 15; i++) {
            assertEquals(q.peek(), new Integer(i));
            q.dequeue();
        }
    }
}