using NUnit.Framework;
using datastructures;
using problemsets;
using System;
using System.Collections.Generic;

namespace Tests
{
    public class ch4Test
    {
        [SetUp]
        public void Setup() {}

        [Test]
        public void createMinBSTTest()
        {
            int[] validInorder  = new int[]{ 1,  2, 3, 4, 5, 8, 9, 10, 12, 15, 20};
            BinarySearchTree bst = ch4.createMinimalBST(validInorder);
            List<int> inOrderList = bst.getInorder();
            Assert.AreEqual(validInorder.Length,bst.count);
            Assert.AreEqual(validInorder.Length,inOrderList.Count);
            for(int i = 0; i < validInorder.Length;i++) {
                Assert.AreEqual(validInorder[i], inOrderList[i]);
            }
        }

        [Test]
        public void createLevelLinkedListTest()
        {
            //             /--------10--------\
            //       /----5----\         /----15---- \
            //    /--3--\   /--8--\  /--12--\     /--20--\
            // /--2--\   4        9
            // 1
            BinarySearchTree bst = new BinarySearchTree();
            int[] addOrder = new int[] { 10, 15, 12, 20, 5, 3, 4, 2, 1, 8, 9 };
            for(int i = 0; i < addOrder.Length; i++) {
                bst.add(addOrder[i]);
            }

            List<BSTNode>[] nodesByHeight = ch4.createLevelLinkedList(bst);
            int[] height1 = new int[] {10};
            int[] height2 = new int[] {5, 15};
            int[] height3 = new int[] {3, 8, 12, 20};
            int[] height4 = new int[] {2,4, 9};
            int[] height5 = new int[] {1};
            int[][] heights = new int[][]{height1, height2, height3, height4, height5};
            Assert.AreEqual(nodesByHeight.Length, heights.Length);
            for(int i = 0; i < heights.Length; i++) {
                Assert.AreEqual(heights[i].Length, nodesByHeight[i].Count);
                for(int j = 0; j < heights[i].Length; j++) {
                    Assert.AreEqual(heights[i][j], nodesByHeight[i][j].data);
                    Assert.AreEqual(i+1, nodesByHeight[i][j].height);
                }
            }
        }

        [Test]
        public void createLevelLinkedListTest2()
        {

            //             /--------8--------\
            //       /----3----\         /----12---- \
            //    /--1--\   /--4--\   /--9--\     /--15--\
            //       /--2--\       5        10            20
    
            int[] validInorder  = new int[]{ 1,  2, 3, 4, 5, 8, 9, 10, 12, 15, 20};
            BinarySearchTree bst = ch4.createMinimalBST(validInorder);
            List<BSTNode>[] nodesByHeight = ch4.createLevelLinkedList(bst);
            int[] height1 = new int[] {8};
            int[] height2 = new int[] {3, 12};
            int[] height3 = new int[] {1, 4, 9, 15};
            int[] height4 = new int[] {2,5, 10, 20};
            int[][] heights = new int[][]{height1, height2, height3, height4};
            Assert.AreEqual(nodesByHeight.Length, heights.Length);
            for(int i = 0; i < heights.Length; i++) {
                Assert.AreEqual(heights[i].Length, nodesByHeight[i].Count);
                for(int j = 0; j < heights[i].Length; j++) {
                    Assert.AreEqual(heights[i][j], nodesByHeight[i][j].data);
                    Assert.AreEqual(i+1, nodesByHeight[i][j].height);
                }
            }

        }
    }
}