using NUnit.Framework;
using datastructures;
using System;
namespace Tests
{
    public class ListTests
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void TestSizeIsZero()
        {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>();
            Assert.AreEqual(0, dl.Size);
            Assert.AreEqual(null, dl.head);
        }

        [Test]
        public void TestSizeIsOne()
        {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>(1);
            Assert.AreEqual(1, dl.Size);
            Assert.IsNotNull(dl.head);
            Assert.IsNull(dl.head.next);
            Assert.IsNull(dl.head.prev);
            Assert.AreEqual(1, dl.head.data);
        }

        [Test]
        public void TestAddToFrontFromNull()
        {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>();
            for(int ii = 10; ii > 0;ii--) {
                dl.addToFront(ii);
            }
            Assert.AreEqual(10, dl.Size);
            DNode<int> curr = dl.head;
            int i = 1;
            while(curr != null) {
                Assert.AreEqual(i, curr.data);
                if(i > 1) {
                    Assert.AreEqual(i-1, curr.prev.data);
                }
                if(i < dl.Size) {
                    Assert.AreEqual(i+1, curr.next.data);
                }
                curr = curr.next;
                i++;
            }
        }
        [Test]
        public void TestAddToFrontFromOne()
        {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>(11);
            for(int ii = 10; ii > 0;ii--) {
                dl.addToFront(ii);
            }
            Assert.AreEqual(11, dl.Size);
            DNode<int> curr = dl.head;
            int i = 1;
            while(curr != null) {
                Assert.AreEqual(i, curr.data);
                if(i > 1) {
                    Assert.AreEqual(i-1, curr.prev.data);
                }
                if(i < dl.Size) {
                    Assert.AreEqual(i+1, curr.next.data);
                }
                curr = curr.next;
                i++;
            }
        }
        [Test]
        public void TestAddToIndexNull() {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>();
            dl.addToIndex(10,0);
            Assert.AreEqual(10, dl.head.data);
            Assert.IsNull(dl.head.next);
            Assert.IsNull(dl.head.prev);

            DoublyLinkedList<int> dl2 = new DoublyLinkedList<int>();
            dl2.addToIndex(10,5);
            Assert.AreEqual(10, dl2.head.data);
            Assert.IsNull(dl2.head.next);
            Assert.IsNull(dl2.head.prev);
        }

        [Test]
        public void TestAddToIndexZero() {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>(11);
            dl.addToIndex(10,0);
            Assert.AreEqual(10, dl.head.data);
            Assert.AreEqual(10, dl.head.next.prev.data);
            Assert.AreEqual(11, dl.head.next.data);
        }

        [Test]
        public void TestAddToIndexNegative() {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>(11);
            dl.addToIndex(10,-1);
            Assert.AreEqual(10, dl.head.data);
            Assert.AreEqual(10, dl.head.next.prev.data);
            Assert.AreEqual(11, dl.head.next.data);
        }

        [Test]
        public void TestAddToIndexMiddle() {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>();
            for(int ii = 4; ii > 0;ii--) {
                dl.addToFront(ii);
            }
            dl.addToIndex(11,2);
            int[] arr = new int[] {1,2,11,3,4};
            Assert.AreEqual(arr.Length, dl.Size);
            DNode<int> curr = dl.head;
            for(int i = 0; i < arr.Length;i++) {
                Assert.AreEqual(arr[i], curr.data);
                if(i > 0) {
                    Assert.AreEqual(arr[i-1], curr.prev.data);
                }
                if(i < dl.Size-1) {
                    Assert.AreEqual(arr[i+1], curr.next.data);
                }
                curr = curr.next;
            }
            
        }

        [Test]
        public void TestAddToIndexEnd() {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>();
            for(int ii = 4; ii > 0;ii--) {
                dl.addToFront(ii);
            }
            int[] arr = new int[] {1,2,3,4,11,12,13};
            dl.addToIndex(11,5);
            dl.addToIndex(12,7);
            dl.addToIndex(13,7);
            Assert.AreEqual(arr.Length, dl.Size);
            DNode<int> curr = dl.head;
            for(int i = 0; i < arr.Length;i++) {
                Assert.AreEqual(arr[i], curr.data);
                if(i > 0) {
                    Assert.AreEqual(arr[i-1], curr.prev.data);
                }
                if(i < dl.Size-1) {
                    Assert.AreEqual(arr[i+1], curr.next.data);
                }
                curr = curr.next;
            }
            
        }
        [Test]
        public void TestDeleteEmpty() {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>();
            dl.delete(dl.head);
            Assert.AreEqual(0, dl.Size); // make sure size does not become negative
            DNode<int> temp = new DNode<int>(1);
            dl.delete(temp);
            Assert.AreEqual(0, dl.Size); // make sure size does not become negative
        }

        [Test]
        public void TestDeleteHead() {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>();
            for(int ii = 5; ii > 0;ii--) {
                dl.addToFront(ii);
            }
            int[] arr = new int[] {2, 3, 4, 5};
            dl.delete(dl.head);
            DNode<int> curr = dl.head;
            for(int i = 0; i < arr.Length;i++) {
                Console.WriteLine("data: " + curr.data);
                Assert.AreEqual(arr[i], curr.data);
                if(i > 0) {
                    Assert.AreEqual(arr[i-1], curr.prev.data);
                }
                if(i < dl.Size-1) {
                    Assert.AreEqual(arr[i+1], curr.next.data);
                }
                curr = curr.next;
            }
        }
        [Test]
        public void TestDeleteAfterHead() {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>();
            for(int ii = 5; ii > 0;ii--) {
                dl.addToFront(ii);
            }
            int[] arr = new int[] {1,3,4,5};
            DNode<int> curr = dl.head.next;
            dl.delete(curr);
            curr = dl.head;
            for(int i = 0; i < arr.Length;i++) {
                Console.WriteLine("data: " + curr.data);
                Assert.AreEqual(arr[i], curr.data);
                if(i > 0) {
                    Assert.AreEqual(arr[i-1], curr.prev.data);
                }
                if(i < dl.Size-1) {
                    Assert.AreEqual(arr[i+1], curr.next.data);
                }
                curr = curr.next;
            }
        }

        [Test]
        public void TestDeleteMiddle() {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>();
            for(int ii = 5; ii > 0;ii--) {
                dl.addToFront(ii);
            }
            int[] arr = new int[] {1,2,4,5};
            DNode<int> curr = dl.head;
            for(int i = 0; i < 2;i++) {
                curr = curr.next;
            }
            dl.delete(curr);
            curr = dl.head;
            for(int i = 0; i < arr.Length;i++) {
                Console.WriteLine("data: " + curr.data);
                Assert.AreEqual(arr[i], curr.data);
                if(i > 0) {
                    Assert.AreEqual(arr[i-1], curr.prev.data);
                }
                if(i < dl.Size-1) {
                    Assert.AreEqual(arr[i+1], curr.next.data);
                }
                curr = curr.next;
            }
        }
        [Test]
        public void TestDeleteEnd() {
            DoublyLinkedList<int> dl = new DoublyLinkedList<int>();
            for(int ii = 5; ii > 0;ii--) {
                dl.addToFront(ii);
            }
            int[] arr = new int[] {1,2,3,4};
            DNode<int> curr = dl.head;
            while(curr.next != null) {
                curr = curr.next;
            }
            dl.delete(curr);
            curr = dl.head;
            for(int i = 0; i < arr.Length;i++) {
                Console.WriteLine("data: " + curr.data);
                Assert.AreEqual(arr[i], curr.data);
                if(i > 0) {
                    Assert.AreEqual(arr[i-1], curr.prev.data);
                }
                if(i < dl.Size-1) {
                    Assert.AreEqual(arr[i+1], curr.next.data);
                }
                curr = curr.next;
            }
        }
    }
}