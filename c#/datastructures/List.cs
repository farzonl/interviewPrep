using System;

namespace datastructures
{
    public class DNode<T> {
        private T _data;
        public T data { 
            get { return this._data; }
            set {this._data = value;}
        }
        public DNode<T> next {get; set;}
        public DNode<T> prev {get; set;}
        public DNode(T data) {
            this.data = data;
            next = null;
            prev = null;
        }
    }
    public class DoublyLinkedList<T> {
        public DNode<T> head {get; protected set;}
        public int Size {get; protected set;}

        public DoublyLinkedList() {
            head = null;
            Size = 0;
        }
        public DoublyLinkedList(T data) {
            head = new DNode<T>(data);
            Size = 1;
        }

        public void addToFront(T data) {
            DNode<T> temp =  new DNode<T>(data);
            if(head == null) {
                head = temp;
                Size = 1;
                return;
            }
            temp.next = head;
            head.prev = temp;
            head = temp;
            Size++;
        }

        public void addToIndex(T data, int index) {
            if(head == null || index <= 0) {
                addToFront(data);
                return;
            }
            int i = 0;
            DNode<T> temp =  new DNode<T>(data);
            DNode<T> curr = head;
            while(curr.next != null) {
                if(i == index) {
                    temp.next = curr;
                    temp.prev = curr.prev;
                    curr.prev.next = temp;
                    curr.prev = temp;
                    Size++;
                    return;
                }
                curr = curr.next;
                i++;
            }
            curr.next = temp;
            temp.prev = curr;
            Size++;
        }
    }
}
