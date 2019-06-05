using NUnit.Framework;
using problemsets;
using System;

namespace Tests
{
    public class googleTests
    {
        [SetUp]
        public void Setup() {}

        [Test]
        public void findLongestTest()
        {
            bool[] b = new bool[] {true, false, false, true, true, true, false, true, true};
            bool[] b2 = new bool[] {false, false, true, true, true, true, false, true, true, true, false, true, true};
            bool[] b3 = new bool[] {true, false, false, false, false };
            bool[] b4 = new bool[] {false, false, false, false, true };
            bool[] b5 = new bool[] {false, false, true, false, false };
            Assert.AreEqual(3, googleQuestions.findLongest(b));
            Assert.AreEqual(4, googleQuestions.findLongest(b2));
            Assert.AreEqual(1, googleQuestions.findLongest(b3));
            Assert.AreEqual(1, googleQuestions.findLongest(b4));
            Assert.AreEqual(1, googleQuestions.findLongest(b5));
        }
        [Test]
        public void TransposeTest() {
             int [][] mat = new int[][]{new int[]{1, 0, 0, 1}, 
                                        new int[]{0, 0, 1, 0}, 
                                        new int[]{0, 0, 0, 0}};
            int[][] resultMat = googleQuestions.transpose(mat);
            int [][] expectedMat = new int[][]{new int[]{1, 0, 0}, 
                                               new int[]{0, 0, 0}, 
                                               new int[]{0, 1, 0},
                                               new int[]{1, 0, 0}};

            Assert.AreEqual(expectedMat,resultMat);
        }
        [Test]
        public void flipMatOnYaxisTest() {
            int [][] mat = new int[][]{new int[]{1, 0, 1, 1}, 
                                        new int[]{1, 1, 0, 0}, 
                                        new int[]{0, 1, 0, 1},
                                        new int[]{0, 0, 1, 1}};
            
            int [][] expectedMat = new int[][]{new int[]{1, 1, 0, 1}, 
                                                new int[]{0, 0, 1, 1}, 
                                                new int[]{1, 0, 1, 0},
                                                new int[]{1, 1, 0, 0}};
            
            int[][] resultMat = googleQuestions.flipMatrix(mat);

            Assert.AreEqual(expectedMat,resultMat);
            
        }
    }
}