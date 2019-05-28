using NUnit.Framework;
using datastructures;
using System;

namespace Tests
{
    public class QuadTreeTests
    {
        Rectangle r;
        Particle[] ps;
        Particle[] nwParticles;
        [SetUp]
        public void Setup()
        {
            r = new Rectangle(50,50,50,50); //Rectangle 100 by 100
            ps = new Particle[] {
                new Particle(25,25),
                new Particle(25,75),
                new Particle(75,25),
                new Particle(75,75)
            };
            nwParticles = new Particle[] {
                new Particle(10,15),
                new Particle(15,20),
                new Particle(15,15),
                new Particle(15,10)
            };
        }

        [Test]
        public void TestRectangle()
        {
            Assert.AreEqual(r.x, 50);
            Assert.AreEqual(r.y, 50);
            Assert.AreEqual(r.w, 50);
            Assert.AreEqual(r.h, 50);
        }
        
        [Test]
        public void TestParticle()
        {
            Assert.AreEqual(ps[0].x, 25);
            Assert.AreEqual(ps[0].y, 25);

            Assert.AreEqual(ps[1].x, 25);
            Assert.AreEqual(ps[1].y, 75);
            
            Assert.AreEqual(ps[2].x, 75);
            Assert.AreEqual(ps[2].y, 25);

            Assert.AreEqual(ps[3].x, 75);
            Assert.AreEqual(ps[3].y, 75);
        }

        [Test]
        public void TestQuadTree()
        {
            QuadTree qtree = new QuadTree(r, 4);
            Assert.AreEqual(4, qtree.capacity);
            Assert.AreEqual(4, qtree.capacity);
            Assert.IsNull(qtree.NW);
            Assert.IsNull(qtree.NE);
            Assert.IsNull(qtree.SW);
            Assert.IsNull(qtree.SE);
            Assert.AreEqual(0, qtree.points.Count);
            Assert.IsFalse(qtree.isSubdivided);
            Assert.AreEqual(r,qtree.boundary);
            for(int i = 0; i < ps.Length; i++) {
                qtree.insert(ps[i]);
            }

            Assert.IsNull(qtree.NW);
            Assert.IsNull(qtree.NE);
            Assert.IsNull(qtree.SW);
            Assert.IsNull(qtree.SE);
            Assert.AreEqual(4, qtree.points.Count);
            Assert.IsFalse(qtree.isSubdivided);

            qtree.insert(nwParticles[0]);

            Assert.IsNotNull(qtree.NW);
            Assert.IsNotNull(qtree.NE);
            Assert.IsNotNull(qtree.SW);
            Assert.IsNotNull(qtree.SE);
            Assert.AreEqual(4, qtree.points.Count);
            Assert.AreEqual(1, qtree.NW.points.Count);
            Assert.AreEqual(0, qtree.NE.points.Count);
            Assert.AreEqual(0, qtree.SW.points.Count);
            Assert.AreEqual(0, qtree.SE.points.Count);
            Assert.IsTrue(qtree.isSubdivided);

            for(int i = 1; i < nwParticles.Length; i++) {
                qtree.insert(nwParticles[i]);
            }
            //ne = x: 75, y: 25, w: 25, h: 25 Range: 50,0 => 100, 50
            //nw = x: 25, y: 25, w: 25, h: 25 Range: 0,0 -> 50,50
            //      38, 13, 12, 12 
            //      13, 13, 12, 12 
            //      38, 38, 12, 12 
            //      13, 38, 12, 12 
            //se = x: 75, y: 75, w: 25, h: 25 Range:  50,50 -> 100,100
            //sw = x: 25, y: 75, w: 25, h: 25 Range: 0, 50 -> 50, 100
            Assert.AreEqual(4, qtree.NW.points.Count);
            Assert.AreEqual(0, qtree.NE.points.Count);
            Assert.AreEqual(0, qtree.SW.points.Count);
            Assert.AreEqual(0, qtree.SE.points.Count);

            Particle p = new Particle(2,37);
            qtree.insert(p);
            Assert.AreEqual(4, qtree.NW.points.Count);
            Assert.AreEqual(1, qtree.NW.SW.points.Count);
            
        }
    }
}