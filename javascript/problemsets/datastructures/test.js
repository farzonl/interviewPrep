import assert from 'assert';
import { SinglyLinkedList } from './SinglyLinkedList.js';

describe('Test basic list Addition', function() {
    it('test if addToFront & toArray works properly', function () {
        let l = new SinglyLinkedList();
        l.addToFront(3);
        l.addToFront(2);
        l.addToFront(1);
        assert.deepEqual(l.toArray(), [1,2,3]);
    });

    it('test if getNodeAt works properly', function () {
        let l = new SinglyLinkedList();
        l.addToFront(3);
        l.addToFront(2);
        l.addToFront(1);
        assert.equal(l.getNodeAt(0).data, 1);
        assert.equal(l.getNodeAt(1).data, 2);
        assert.equal(l.getNodeAt(2).data, 3);
        assert.equal(l.getNodeAt(3), null);
        assert.equal(l.getNodeAt(4), null);
    });

    it('test if we can detect cycle', function () {
        let l = new SinglyLinkedList();
        l.addToFront(5);
        l.addToFront(4);
        l.addToFront(3);
        l.addToFront(2);
        l.addToFront(1);
        let lastNode = l.getNodeAt(4);
        assert.equal(lastNode.data, 5);
        assert.equal(lastNode.next, null);
        let newNext = l.getNodeAt(2);
        lastNode.next = newNext;
        try {
            l.toArray();
            assert.fail("should not get here");
        } catch (err) {
            assert.equal(l.detectCycle(), true);
            assert.equal(l.detectCycleKeyTable(), true);
        }
    });

    it('test if we do not detect cycle', function () {
        let l = new SinglyLinkedList();
        l.addToFront(5);
        l.addToFront(4);
        l.addToFront(3);
        l.addToFront(2);
        l.addToFront(1);
        try {
            assert.deepEqual(l.toArray(), [1,2,3,4,5]);
        } catch (err) {
            assert.fail("should not get here");
        }
        assert.equal(l.detectCycle(), false);
        assert.equal(l.detectCycleKeyTable(), false);
    });

});