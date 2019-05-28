using System;
using datastructures;
using System.Collections.Generic;
using System.Linq;

namespace problemsets
{
    public static class ch4
    {
        public static BinarySearchTree createMinimalBST(int[] array) {
            BinarySearchTree bst = new BinarySearchTree();
            createMinimalBST(array, 0, array.Length -1, ref bst);
            return bst;
        }
        private static void createMinimalBST(int[] array, int start, int end, ref BinarySearchTree bst) {
            if (end < start) {
                return;
            }
            int midPoint = (start + end) / 2;
            bst.add(array[midPoint]);
            createMinimalBST(array, start, midPoint - 1, ref bst);
            createMinimalBST(array, midPoint + 1, end, ref bst);
        }

        public static List<BSTNode>[] createLevelLinkedList(BinarySearchTree bst) {
            if(bst == null || bst.count == 0) {
                return null;
            }
            int maxHeight = bst.maxDepth();
            List<BSTNode>[] nodesByHeight = new List<BSTNode>[maxHeight].Select(_ => new List<BSTNode>()).ToArray();
            PopulateInorder(bst.Root, nodesByHeight);
            return nodesByHeight;
        }

        private static void PopulateInorder(BSTNode curr, List<BSTNode>[] nodesByHeight) {
            if(curr == null) {
                return;
            }
            PopulateInorder(curr.Left, nodesByHeight);
            nodesByHeight[curr.height - 1].Add(curr);
            PopulateInorder(curr.Right, nodesByHeight);
        }
    }
}