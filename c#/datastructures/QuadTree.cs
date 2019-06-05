using System;
using System.Collections.Generic;

namespace datastructures
{
    public interface IPoint {
        int x {get; set;}
        int y {get; set;}
    }

    public interface IBoundary {
        bool contains(IPoint p);
        bool intersects(IBoundary b);
    }

    public class Rectangle : IBoundary {
        public int x {get; private set;}
        public int y {get; private set;}
        public int w {get; private set;}
        public int h {get; private set;}
        public Rectangle(int x, int y, int w, int h) {
            this.x = x;
            this.y = y;
            this.w = w;
            this.h = h;
        }

        // center +- width and height
        public bool contains(IPoint p) {
            return p.x > (this.x - this.w ) &&
                   p.x < (this.x + this.w)  &&
                   p.y > (this.y - this.h)  &&
                   p.y < (this.y + this.h);
        }

        public bool intersects(IBoundary b) {
            if(b is Rectangle) {
                return intersects( b as Rectangle);
            }
            return false;
        }

        public bool intersects(Rectangle rect) {
            return intersects(this, rect);
        }

        // https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection
        public  static bool intersects(Rectangle rect1, Rectangle rect2) {
            return (rect1.x < rect2.x + rect2.w &&
                    rect1.x + rect1.w > rect2.x &&
                    rect1.y < rect2.y + rect2.h &&
                    rect1.y + rect1.h > rect2.y);
        }
    }

    public class Particle : IPoint {
        public int x {get; set;}
        public int y {get; set;}
        public Particle(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public class QuadTree {
        public int capacity {get; private set;}
        public QuadTree NW,NE,SW,SE;
        public List<IPoint> points {get; private set;}
        public Rectangle boundary {get; private set;}
        public bool isSubdivided {get; private set;}

        public QuadTree(Rectangle boundary, int capacity=10) {
            this.capacity = capacity;
            this.boundary = boundary;
            isSubdivided = false;
            points = new List<IPoint>();
        }

        public bool insert(IPoint p) {
            if(!this.boundary.contains(p)) {
                return false;
            }
            if(points.Count < capacity) {
                points.Add(p);
                return true;
            } 
            if(!isSubdivided) {
                subdivide();
            }
            if(NW.insert(p)) {
                Console.WriteLine("North west add");
                return true;
            } else if(NE.insert(p)) {
                Console.WriteLine("North east add");
                return true;
            } else if (SW.insert(p)) {
                Console.WriteLine("South west add");
                return true;
            } else if (SE.insert(p)) {
                Console.WriteLine("South east add");
                return true;
            }
            return false;
        }

        //  _________
        // | NW | NE |
        // |____|____|
        // | SW | SE |
        // |____|____|
        public void subdivide() {
            int x = this.boundary.x;
            int y = this.boundary.y;
            int w = this.boundary.w;
            int h = this.boundary.h;
            Rectangle neR = new Rectangle(x + w / 2, y - h/2, w / 2, h / 2 );
            Rectangle nwR = new Rectangle(x - w / 2, y - h/2, w / 2, h / 2 );
            Rectangle seR = new Rectangle(x + w / 2, y + h/2, w / 2, h / 2 );
            Rectangle swR = new Rectangle(x - w / 2, y + h/2, w / 2, h / 2 );
            NW = new QuadTree(nwR, this.capacity);
            NE = new QuadTree(neR, this.capacity);
            SW = new QuadTree(swR, this.capacity);
            SE = new QuadTree(seR, this.capacity);
            isSubdivided = true;
        }
        public List<IPoint> query(IBoundary range) {
            List<IPoint> foundPnts = new List<IPoint>();
            return query(range, foundPnts);
        }
        private List<IPoint> query(IBoundary range, List<IPoint> foundPnts) {
            if(!this.boundary.intersects(range)) {
                return foundPnts;
            }
            // add top quad tree points
            foreach(IPoint p in points) {
                if(range.contains(p)) {
                    foundPnts.Add(p);
                }
           }
            // add child quad tree points
            //then recursivly add
            if (this.isSubdivided) {
                NW.query(range, foundPnts);
                NE.query(range, foundPnts);
                SW.query(range, foundPnts);
                SE.query(range, foundPnts);
            }

            return foundPnts;
        }
    }
}