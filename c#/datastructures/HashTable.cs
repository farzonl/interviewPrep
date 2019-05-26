using System;
using System.Linq;

namespace datastructures
{
    public class KeyValuePair<K, V> {
        public K Key {get; protected set;}
        public V Value {get; protected set;}

        public KeyValuePair(K key, V value) {
		    Key = key;
		    Value = value;
        }
    }
    public class HashTable<K, V> {
        private DoublyLinkedList<KeyValuePair<K, V>>[] table;
        public DoublyLinkedList<KeyValuePair<K, V>>[] Table {get { return table;}}
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
            table = new DoublyLinkedList<KeyValuePair<K, V>>[tableSize].Select(_ => new DoublyLinkedList<KeyValuePair<K, V>>()).ToArray();
        }

        public void clear() {
		    Size = 0;
            int tableSize = TableSize; // cache this
		    table = new DoublyLinkedList<KeyValuePair<K, V>>[tableSize].Select(_ => new DoublyLinkedList<KeyValuePair<K, V>>()).ToArray();
	    }

        public bool isEmpty() {
            return Size == 0;
	    }
        
        public int hash(K key) {
            return hash(key,TableSize);
        }

        public int hash(K key, int modValue) {
            int total = 0;
		    if (key == null) {
		    	throw new System.ArgumentException("Parameter cannot be null", "key");
            }
		    for(int i=0; i < key.ToString().Length; i++) {
		    	total += (key.ToString()[i]);
		    }

		//see which count to use?
		return total % modValue;
        }
        
        public void reHash() {
            int reTableSize = 2*TableSize;
             DoublyLinkedList<KeyValuePair<K, V>>[] reTable 
                = new DoublyLinkedList<KeyValuePair<K, V>>[reTableSize].Select(_ => new DoublyLinkedList<KeyValuePair<K, V>>()).ToArray();
            for(int i = 0;i<TableSize;i++) { 
                DNode<KeyValuePair<K, V>> curr = table[i].head;
                while(curr != null) {
                    int hashIndex = hash(curr.data.Key,reTableSize);
                    reTable[hashIndex].addToFront(curr.data);
                    curr = curr.next;
                }
            }
            table = reTable;
        }

        public bool put(K key, V value) {
            if(percentage>= LoadFactor) {
                reHash();
            }
            int hashIndex = hash(key);
            KeyValuePair<K, V> entry = new KeyValuePair<K, V>(key, value);
            table[hashIndex].addToFront(entry);
            Size++;
            return true;
        }

        public bool containsKey(K key) {
            DNode<KeyValuePair<K, V>> curr = table[hash(key)].head;
            while(curr != null) {
                K currentKey = curr.data.Key;
                if(currentKey.Equals(key)) {
                    return true;
                }
                curr = curr.next;
            }
            return false;
        }

        public bool delete(K key,V value) {
            DoublyLinkedList<KeyValuePair<K, V>> list = table[hash(key)];
            DNode<KeyValuePair<K, V>> curr = list.head;
            while(curr != null) {
                K currKey = curr.data.Key;
                V currValue = curr.data.Value;
                if(currKey.Equals(key) && currValue.Equals(value) ) {
                    list.delete(curr);
                    Size--;
                    return true;
                }
                curr = curr.next;
            }
            return false;
        }
    }
}