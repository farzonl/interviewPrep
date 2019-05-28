using System;
using System.Collections.Generic;

namespace datastructures
{
    public class BSTNode {
        public BSTNode Left {get; set;}
        public BSTNode Right {get; set;}
        public int data {get; private set;} // TODO make this generic with c# equivalent of comparable
        public int height {get; set;}
        public BSTNode(int data) {
            this.data = data;
        }
    }
    public class BinarySearchTree {
        public BSTNode Root {get; private set;}
        public int count {get; private set;}
        public BinarySearchTree() {
            count = 0;
        }
        
        public void add(int value) {
            BSTNode newLeaf = new BSTNode(value);
            if(Root == null) {
                Root = newLeaf;
                Root.height = 1;
                count = 1;
                return;
            }
            addHelper(Root, newLeaf);
            count++;
        }

        // if newLeaf > curr go right
        // if newLeaf <= curr go left
        private void addHelper(BSTNode curr, BSTNode newLeaf) {
            if (newLeaf.data > curr.data) {
                if(curr.Right == null) {
                    curr.Right = newLeaf;
                    curr.Right.height = curr.height + 1;
                    return;
                } else {
                    addHelper(curr.Right, newLeaf);
                }
            } else {
                if(curr.Left == null) {
                    curr.Left =  newLeaf;
                    curr.Left.height = curr.height + 1;
                    return;
                } else {
                    addHelper(curr.Left, newLeaf);
                }
            }
        }
        public List<int> getInorder() {
            List<int> returnList = new List<int>();
            getInorder(Root, returnList);
            return returnList;
        }

        private void getInorder(BSTNode curr, List<int> arrList) {
            if(curr == null) {
                return;
            }
            getInorder(curr.Left, arrList);
            arrList.Add(curr.data);
            getInorder(curr.Right, arrList);
        }

        public List<int> getPreorder() {
            List<int> returnList = new List<int>();
            getPreorder(Root, returnList);
            return returnList;
        }

        private void getPreorder(BSTNode curr, List<int> arrList) {
            if(curr == null) {
                return;
            }
            arrList.Add(curr.data);
            getPreorder(curr.Left, arrList);
            getPreorder(curr.Right, arrList);
        }

        public List<int> getPostrder() {
            List<int> returnList = new List<int>();
            getPostrder(Root, returnList);
            return returnList;
        }

        private void getPostrder(BSTNode curr, List<int> arrList) {
            if(curr == null) {
                return;
            }
            getPostrder(curr.Left, arrList);
            getPostrder(curr.Right, arrList);
            arrList.Add(curr.data);
        }

        public int maxDepth() {
            return maxDepth(Root);
        }
        /*private int max(int a, int b) { // replace with library
            if (a > b) {
                return a;
            }
            return b;
        }*/
        private int maxDepth(BSTNode curr) {
            if(curr == null) {
                return 0;
            }
            return 1 + Math.Max(maxDepth(curr.Left), maxDepth(curr.Right));
        }

        public bool isBallanced() {
            return isBalanced(Root);
        }

        private bool isBalanced(BSTNode curr) {
            if(curr == null) {
                return true;
            }
            int heightDiff = maxDepth(curr.Left) - maxDepth(curr.Right);
            if (Math.Abs(heightDiff) > 1) {
                return false;
            } else { // recurse
                return isBalanced(curr.Left) && isBalanced(curr.Right);
            }
        }

    }
}
