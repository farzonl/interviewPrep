using System;
using System.Collections.Generic;
using datastructures;
using System.Linq;

namespace problemsets
{
    public static class googleQuestions
    {
        public static int findLongest(bool[] b) {
            int[] arr = new int[b.Length];
            if(b[0] == true) {
                arr[0] = 1;
            } else {
                arr[0] = 0;
            }
            for(int i = 1; i < b.Length; i++) {
                if(b[i]) {
                    arr[i] = arr[i-1] + 1;
                } else {
                    arr[i] = 0;
                }
            }
            int max = -1;
            for(int i = 0; i < b.Length; i++) {
                if(arr[i] > max) {
                    max = arr[i];
                }
            }
            return max;
        }
        //idea get inorder then do a binary search insertion of the sorted elements
        public static BinarySearchTree compactBST(BinarySearchTree bst) {
            int[] inOrderList = bst.getInorder().ToArray();
            BinarySearchTree bst2 = ch4.createMinimalBST(inOrderList);
            return bst2;
        }

        public static int smallestRectArea(int[][] points) {
            return 0; // look into
        }
        public static int[][] flipMatrix(int[][] mat) {
            int R = mat.Length;
            int C = mat[0].Length;
            int[][] newMat = new int[C].Select(_ => new int[R]).ToArray();
            for (int i = 0; i < R; i++)  { 
                for (int j = 0, k = C-1; j < C; k--, j++) { 
                    newMat[i][k] = mat[i][j];
                } 
            } 
            return newMat;
        }

        public static int[][] transpose(int[][] mat) {
            int R = mat.Length;
            int C = mat[0].Length;
            int[][] newMat = new int[C].Select(_ => new int[R]).ToArray();

            // Traverse the input matrix mat[M][N]. If you see an 
            // entry mat[i][j] as true, then mark row[i] and col[j] as true.
            for (int i = 0; i < R; i++)  { 
                for (int j = 0; j < C; j++) { 
                    newMat[j][i] = mat[i][j];
                } 
            } 
            return newMat;
        } 
        public static void modifyMatrix(int[][] mat) {
            int R = mat.Length;
            int C = mat[0].Length;

            // Create two temporary arrays row[M] and col[N]. 
            int []row = new int [R]; 
            int []col = new int [C]; 
            // Initialize all values of row[] and col[] as 0.
            Array.Clear(row, 0, row.Length);
            Array.Clear(col, 0, col.Length);

            // Traverse the input matrix mat[M][N]. If you see an 
            // entry mat[i][j] as true, then mark row[i] and col[j] as true.
            for (int i = 0; i < R; i++)  { 
                for (int j = 0; j < C; j++) { 
                    if (mat[i][j] == 1) { 
                        row[i] = 1; 
                        col[j] = 1; 
                    } 
                } 
            } 

            // Traverse the input matrix mat[M][N] again. 
            // For each entry mat[i][j], check the values of row[i] and col[j]. 
            // If any of the two values (row[i] or col[j]) is true, then mark mat[i][j] as true.
            for (int i = 0; i < R; i++)  { 
                for (int j = 0; j < C; j++) { 
                    if (row[i] == 1 || col[j] == 1) { 
                        mat[i][j] = 1; 
                    } 
                } 
            } 
        } 
    }

}