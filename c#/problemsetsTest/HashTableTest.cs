using NUnit.Framework;
using datastructures;

namespace Tests
{
    public class HashTableTests
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void TestSizeIsZero()
        {
            HashTable<string,string> ht = new HashTable<string,string>();
            Assert.AreEqual(0, ht.Size);
            Assert.AreEqual(0.0, ht.percentage);
            Assert.AreEqual(10, ht.TableSize);
            Assert.IsTrue(ht.isEmpty());
        }

        [Test]
        public void TestSizeIsOne()
        {
            HashTable<string,string> ht = new HashTable<string,string>();
            ht.put("a","hello");
            Assert.AreEqual(1, ht.Size);
            Assert.AreEqual(1/10.0, ht.percentage);
            Assert.AreEqual(10, ht.TableSize);
            Assert.IsFalse(ht.isEmpty());
        }

        [Test]
        public void TestReSize()
        {
            HashTable<string,string> ht = new HashTable<string,string>();
            ht.put("a","hello"); // 1
            ht.put("b","friend"); // 2
            ht.put("c","how");    // 3
            ht.put("d","are");    // 4
            ht.put("e","you");    // 5
            ht.put("f","what");   // 6
            ht.put("g","is");     // 7
            ht.put("h","bothering"); // 8

            Assert.AreEqual(8, ht.Size);
            Assert.AreEqual(8/10.0, ht.percentage);
            Assert.AreEqual(10, ht.TableSize);

            string[] arr = new string[]{"d", "e", "f", "g", "h","i","j","a", "b", "c" };
            for(int i = 0; i < arr.Length;i++) {
                if(arr[i] == "i" || arr[i] == "j") {
                    Assert.IsNull(ht.Table[i].head);
                } else {
                    Assert.AreEqual(arr[i], ht.Table[i].head.data.Key);
                }
            }
            ht.put("i","you"); // 9
            Assert.AreEqual(9, ht.Size);
            Assert.AreEqual(9/20.0, ht.percentage);
            Assert.AreEqual(20, ht.TableSize);
            Assert.IsFalse(ht.isEmpty());
        }

        [Test]
        public void TestCollision()
        {
            HashTable<string,string> ht = new HashTable<string,string>();
            ht.put("a","hello"); // 1
            ht.put("k","friend"); // 2
            Assert.AreEqual(2, ht.Size);
            Assert.AreEqual(2/10.0, ht.percentage);
            Assert.AreEqual(10, ht.TableSize);
            int index = ((int)'a') % 10;
            DNode<KeyValuePair<string,string>> curr =  ht.Table[index].head; 
            Assert.AreEqual("k", curr.data.Key);
            Assert.AreEqual("a", curr.next.data.Key);

            Assert.AreEqual("friend", curr.data.Value);
            Assert.AreEqual("hello", curr.next.data.Value);
        }

        [Test]
        public void TestContains() {
            HashTable<string,string> ht = new HashTable<string,string>();
            ht.put("a","hello"); // 1
            ht.put("b","friend"); // 2
            ht.put("c","how");    // 3
            ht.put("d","are");    // 4
            ht.put("e","you");    // 5
            ht.put("f","what");   // 6
            ht.put("g","is");     // 7
            ht.put("h","bothering"); // 8
            string[] arr = new string[]{"d", "e", "f", "g", "h","i","j","a", "b", "c" };
            for(int i = 0; i < arr.Length;i++) {
                if(arr[i] == "i" || arr[i] == "j") {
                    Assert.IsFalse(ht.containsKey(arr[i]));
                } else {
                    Assert.IsTrue(ht.containsKey(arr[i]));
                }
            }
            ht.put("i","you"); // triggers resize
            Assert.IsTrue(ht.containsKey("i"));
        }

        [Test]
        public void TestClear() {
            HashTable<string,string> ht = new HashTable<string,string>();
            ht.put("a","hello"); // 1
            ht.put("b","friend"); // 2
            ht.put("c","how");    // 3
            ht.put("d","are");    // 4
            ht.put("e","you");    // 5
            ht.put("f","what");   // 6
            ht.put("g","is");     // 7
            ht.put("h","bothering"); // 8
            ht.put("i","you"); // triggers resize
            ht.clear();
            Assert.AreEqual(0, ht.Size);
            Assert.AreEqual(0.0, ht.percentage);
            Assert.AreEqual(20, ht.TableSize);
            Assert.IsTrue(ht.isEmpty());
        }

        [Test]
        public void TestDelete() {
            HashTable<string,string> ht = new HashTable<string,string>();
            ht.put("a","hello"); // 1
            ht.put("b","friend"); // 2
            ht.put("c","how");    // 3
            ht.put("d","are");    // 4
            ht.put("e","you");    // 5
            ht.put("f","what");   // 6
            ht.put("g","is");     // 7
            ht.put("h","bothering"); // 8
            KeyValuePair<string, string>[] arr = new KeyValuePair<string, string>[]
            { new KeyValuePair<string, string>("a","hello"), 
              new KeyValuePair<string, string>("b","friend"),
              new KeyValuePair<string, string>("c","how"),
              new KeyValuePair<string, string>("d","are"),
              new KeyValuePair<string, string>("e","you"),
              new KeyValuePair<string, string>("f","what"),
              new KeyValuePair<string, string>("g","is"),
              new KeyValuePair<string, string>("h","bothering")};
            for(int i = 0; i < arr.Length;i++) {
                if(arr[i].Key == "i" || arr[i].Key == "j") {
                    Assert.IsFalse(ht.containsKey(arr[i].Key));
                } else {
                    Assert.IsTrue(ht.containsKey(arr[i].Key));
                    ht.delete(arr[i].Key, arr[i].Value);
                    Assert.IsFalse(ht.containsKey(arr[i].Key));
                }
            }

        }
    }
}