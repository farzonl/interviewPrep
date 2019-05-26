using System;
using System.Linq;

namespace datastructures
{
    public class KeyValuePair<K, V> {
        public K Key {get; protected set;}
        public V Value {get; protected set;}

        KeyValuePair(K key, V value) {
		    Key = key;
		    Value = value;
        }
    }
    public class HashTable<K, V> {
        private DoublyLinkedList<KeyValuePair<K, V>>[] table;
        private double loadFactor = .75;

        public int Size {get; protected set;}

        public int TableSize {
            get { return table.Length; }
        }
        public double percentage {
            get { return Size / (double) TableSize; }
        }
        
        public double LoadFactor { 
            get { return loadFactor; }
            set { loadFactor = value; }
        }

        public HashTable(int tableSize=10) {
            Size = 0;
            table = Enumerable.Repeat(new DoublyLinkedList<KeyValuePair<K, V>>(), tableSize).ToArray();
        }

        public void clear() {
		    Size = 0;
            int tableSize = TableSize; // cache this
		    table = Enumerable.Repeat(new DoublyLinkedList<KeyValuePair<K, V>>(), tableSize).ToArray();
	    }

        public bool isEmpty() {
            return Size == 0;
	    }

        public bool put(K key, V value) {
            return false;
        }
    }
}