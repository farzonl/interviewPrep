using NUnit.Framework;
using datastructures;
using System;
using System.Collections.Generic;

namespace Tests
{
    public class BinarySearchTreeTests
    {
        [SetUp]
        public void Setup() {}
        [Test]
        public void TestBST()
        {
            BinarySearchTree bst = new BinarySearchTree();
            Assert.AreEqual(0, bst.count);
            //             /--------10--------\
            //       /----5----\         /----15---- \
            //    /--3--\   /--8--\  /--12--\     /--20--\
            // /--2--\   4        9
            // 1             
            int[] validInorder  = new int[]{ 1,  2, 3, 4, 5, 8, 9, 10, 12, 15, 20};
            int[] validPreorder = new int[]{ 10, 5, 3, 2, 1, 4, 8, 9,  15, 12, 20};
            int[] validPostrder = new int[]{ 1,  2, 4, 3, 9, 8, 5, 12, 20, 15, 10};
            int[] addOrder = new int[] { 10, 15, 12, 20, 5, 3, 4, 2, 1, 8, 9 };
            for(int i = 0; i < addOrder.Length; i++) {
                bst.add(addOrder[i]);
            }
            Assert.AreEqual(5, bst.maxDepth());
            List<int> inOrderList = bst.getInorder();
            Assert.AreEqual(validInorder.Length,bst.count);
            Assert.AreEqual(validInorder.Length,inOrderList.Count);
            for(int i = 0; i < validInorder.Length;i++) {
                Assert.AreEqual(validInorder[i], inOrderList[i]);
            }

            List<int> preOrderList = bst.getPreorder();
            Assert.AreEqual(validPreorder.Length,preOrderList.Count);
            for(int i = 0; i < validPreorder.Length;i++) {
                //Console.WriteLine("preOrderList["+i+"] = "+preOrderList[i]);
                Assert.AreEqual(validPreorder[i], preOrderList[i]);
            }

            List<int> postOrderList = bst.getPostrder();
            Assert.AreEqual(validPostrder.Length,postOrderList.Count);
            for(int i = 0; i < validPostrder.Length;i++) {
                //Console.WriteLine("postOrderList["+i+"] = "+postOrderList[i]);
                Assert.AreEqual(validPostrder[i], postOrderList[i]);
            }
        }
    }

}