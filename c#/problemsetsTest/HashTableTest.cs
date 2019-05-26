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
            Assert.AreEqual(0.0, ht.Size);
            Assert.AreEqual(10, ht.TableSize);
            Assert.IsTrue(ht.isEmpty());
        }
    }
}