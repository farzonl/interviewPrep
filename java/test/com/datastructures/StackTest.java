package com.datastructures;

import org.junit.Test;
import static org.junit.Assert.*;

public class StackTest {

    @Test
    public void testPeek() {
        Stack<Integer> s = new Stack<Integer>();
        assertNull(s.peek());
        s.push(5);
        assertEquals(s.peek(), new Integer(5));
        Stack<Integer> s2 = new Stack<Integer>(6);
        assertEquals(s2.peek(), new Integer(6));
    }

    @Test
    public void testPushPop() {
        Stack<Integer> s = new Stack<Integer>();
        for(int i = 0; i < 10; i++) {
            s.push(i);
        }
        for(int i = 9; i > -1; i--) {
            assertEquals(s.peek(), new Integer(i));
            s.pop();
        }
    }
}